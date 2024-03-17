from django.urls import re_path
from . import consumers
from channels.routing import ProtocolTypeRouter 

application = ProtocolTypeRouter({
    # Empty for now (http->django views is added by default)
})

websocket_urlpatterns = [
    re_path(r'ws/socket-server/(?P<username>.*)$', consumers.ChatConsumer.as_asgi())
]