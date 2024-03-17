
import json
from django.views.decorators.http import require_http_methods
from django.http import HttpRequest, HttpResponseNotFound, JsonResponse
from trascendence.api.models.User import UserModel
from trascendence.api.dto import user_dto


@require_http_methods(['GET'])
def search_user(request, username: str):
    user_query = UserModel.objects.filter(username__startswith=username)
    if user_query.exists():
        response = {
            "length": len(user_query),
            "content": [user_dto(user) for user in user_query]
        }
        return JsonResponse(response, status=200)
    return HttpResponseNotFound(json.dumps({"message": f"no match for keyword {username}"}))