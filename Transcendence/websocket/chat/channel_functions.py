from .models import Message
from django.utils.dateformat import DateFormat

def message_dto(message):
    return {
        "author": message.author,
        "audience": message.audience,
        "content": message.content,
        "timestamp": DateFormat(message.timestamp).format('Y-m-d H:i:s')
    }

def fetch_messages(author, audience, amount):
    messages = [message_dto(message) for message in Message.last_n_messages(author, audience, amount)]
    return {
        "length": len(messages),
        "content": messages
    }

def save_message(author, audience, content):
    message = Message.objects.create(author=author, audience=audience, content=content)
    return message_dto(message)

CHANNEL_FUNCTIONS = {
    "fetch",
    "send"
}