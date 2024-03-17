from django.test import TestCase, Client
from django.contrib.auth.models import User
from chat.models import Message
from django.urls import reverse
import websocket
import json

class ChatMessageTest(TestCase):
    def setUp(self):
        self.client = Client()
        self.user = User.objects.create_user(username='testUser1', password='testpass')
        self.client.login(username='testUser1', password='testpass')

    def test_message_saving(self):
        ws_url = 'ws://localhost:8000/ws/socket-server/testUser1'
        ws = websocket.create_connection(ws_url)
        ws.send(json.dumps({
            'type': 'message',
            'message': 'Test message',
            'to': 'anotherUser'
        }))
        result = ws.recv()
        print("Recieved '%s'" % result)
        ws.close()
