import json
from channels.generic.websocket import WebsocketConsumer
from channels.auth import login, logout
from asgiref.sync import async_to_sync
from django.contrib.auth.models import AnonymousUser
from .models import Message
from django.utils.dateformat import DateFormat
from django.contrib.auth.tokens import default_token_generator
from django.conf import settings
from django.utils.http import urlsafe_base64_decode
from django.core.exceptions import ObjectDoesNotExist
from django.contrib.auth.models import User
import requests
import re
from chat.core import authorize_token

# TODO: bu APP_NAME değerini .env dosyasından çek
APP_NAME = "localhost"

"""
    Fiiller
    fetch: mesajları çekme
    send: mesaj gönderme
    ping: durum görüntüleme
"""

class ChatConsumer(WebsocketConsumer):

    def send_chat_message(self, message, sendto):
        new_message = Message.objects.create(author=self.room_group_name, audience=sendto, content=message)
        async_to_sync(self.channel_layer.group_send)(
            sendto,
            {
                'type':'chat_message',
                'message':{
                    "type": "message",
                    "message": message,
                    "from": self.room_group_name,
                    "timestamp": new_message.timestamp.isoformat()
                }
            }
        )

    def push_notification(self, event):
        text = event['text']

        self.send(text_data=text)

    def chat_message(self, event):
        message = event['message']

        self.send(text_data=json.dumps(message))


    def connect(self):
        path = self.scope["path"]
        url_pattern = r"^/ws/socket-server/(.*)$"
        username = re.match(url_pattern, path).group(1)
        
        self.room_group_name = username
        async_to_sync(self.channel_layer.group_add)(
            self.room_group_name,
            self.channel_name
        )

        self.accept()
    
    def disconnect(self, close_code):
        async_to_sync(self.channel_layer.group_discard)(
            self.room_group_name,
            self.channel_name
        )

    def pong(self, target):
        async_to_sync(self.channel_layer.group_send)(
            target,
            {
                "type": "chat_message",
                "message": {
                    "type": "pong",
                    "from": self.room_group_name,
                }
            }
        )
    def ping(self, target):
        async_to_sync(self.channel_layer.group_send)(
            target,
            {
                "type": "chat_message",
                "message": {
                    "type": "ping",
                    "from": self.room_group_name,
                }
            }
        )

    def fetch_messages(self, data):
        user_id = self.room_group_name
        target_user_id = data.get("target")
        fetch_amount = int(data.get("amount"))
        messages = Message.last_n_messages(user_id, target_user_id, fetch_amount)
        import sys
        print("len of messages", len(messages), file=sys.stderr)
        for message in messages:
            msg_json = {
                "type": "message",
                "message": message.content,
                "from": message.author,
                "timestamp": message.timestamp.isoformat()
            }
            self.send(json.dumps(msg_json))

    def receive(self, text_data):
        data = json.loads(text_data)
        token = data.get("token", None)
        if token is None:
            # yetki yok
            pass
        ## token'i değerlendir eğer token değerlendirilmemişse frontedin anlayacağı bi değer döndür
        authorize_token(token)
        message_type = data.get("type", None)
        if message_type == "ping":
            self.ping(data.get("to"))
        elif message_type == "pong":
            self.pong(data.get("to"))
        elif message_type == "message":
            self.send_chat_message(data.get("message"), data.get("to"))
        elif message_type == "fetch-message":
            self.fetch_messages(data)
        else:
            self.send(json.dumps({"message": "You need to set type for message type"}))
