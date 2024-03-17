from django.views.decorators.http import require_http_methods
from channels.layers import get_channel_layer
import json
import re
import requests
from django.shortcuts import render
from django.http import HttpResponse
from .dto import dto_notification
from asgiref.sync import async_to_sync

APP_NAME = "http://backend:8000"

# @login_required
def lobby(request):
    return render(request, 'chat/lobby.html')

@require_http_methods(['POST'])
def push_notification(request, username):
    auth_header = request.headers.get("Authorization")
    if auth_header is None:
        return HttpResponse(status=401)
    if request.content_type != "application/json":
        return HttpResponse(staus=415)
    response = requests.get(f"{APP_NAME}/api/auth/token", headers={"Authorization": auth_header})
    if not response.ok:
        return HttpResponse(status=401)
    json_body = json.loads(request.body)

    if "message" not in json_body.keys():
        return HttpResponse(400)
    if "resource_group" not in json_body.keys():
        return HttpResponse(400)
    if "resource_code" not in json_body.keys():
        return HttpResponse(400)

    msessage_content = json_body["message"]
    resource_code = json_body["resource_code"]
    resource_group = json_body["resource_group"]

    message = dto_notification(username, msessage_content, resource_group, resource_code)
    async_to_sync(get_channel_layer().group_send)(
        username,
        {
            "type": "push_notification",
            "text": json.dumps(message)
        }
    )
    return HttpResponse(status=200)