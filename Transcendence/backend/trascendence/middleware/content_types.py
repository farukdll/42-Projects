import json

from django.http import HttpRequest, HttpResponse

def json_serializer(value):
    return dict(value)

def content_json(response_view):
    """
    Sets attribute `content_json` for json parsed bodies
    """
    def wrapper(request: HttpRequest, *args):
        body_json = json.loads(request.body)
        setattr(request, "content_json", body_json)
        return response_view(request)
    return wrapper
