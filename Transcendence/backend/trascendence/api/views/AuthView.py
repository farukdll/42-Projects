from django.http import HttpRequest, HttpResponse, HttpResponseNotFound, JsonResponse,  HttpResponseBadRequest, \
    HttpResponseForbidden, HttpResponseServerError
from django.views.decorators.http import require_http_methods
from trascendence.middleware.auth import authorize
import traceback
import json
from trascendence.api.models.User import UserModel
from ..api_42 import get_42_token
from trascendence.core.token_manager import generate_refresh_token, generate_access_token
from ..serializers import serialize_json
from ...middleware.validators import request_body, str_field, number_field
from trascendence.api.api_42 import get_user_info
from django.contrib.auth.hashers import BCryptPasswordHasher
from trascendence.api.dto import auth_dto
from django.db.models import Q

@require_http_methods(['POST'])
@request_body(
    content_type="application/json",
    fields={
        "username": str_field(required=True),
        "password": str_field(required=True)
    }
)
def sign_in(request: HttpRequest, content: dict) -> HttpResponse:
    query = UserModel.objects.filter(Q(username=content['username']) | Q(email=content['username']))
    if not query.exists():
        return HttpResponseNotFound(json.dumps({'message': 'user not found'}), content_type="application/json")
    user = query.first()
    hasher = BCryptPasswordHasher()
    if hasher.verify(content.get('password'), user.password):
        access_token = generate_access_token(user)
        refresh_token = generate_refresh_token(user)
        return JsonResponse(auth_dto(user, access_token, refresh_token), status=200)
    return HttpResponseForbidden(json.dumps({'message': 'Invalid credentials.'}), content_type='application.json')


@require_http_methods(['POST'])
@request_body(
    content_type="application/json",
    fields={
        "code": str_field(required=True)
    }
)
def sign_in_42(request: HttpRequest, content: dict) -> JsonResponse:
    code = content["code"]
    print(code)
    try:
        response = get_42_token(code)
    except Exception:
        traceback.print_exc()
        return HttpResponseServerError
    if response["ok"]:
        created_new = False
        token = response["content"]["access_token"]
        info_response = get_user_info(token)
        user_42 = info_response["content"]
        user_db_query = UserModel.objects.filter(intraId=user_42["id"])
        if user_db_query.exists():
            user_db = user_db_query.first()
        else:
            user_db = UserModel.objects.create(
                intraId=user_42["id"],
                name=user_42["first_name"],
                surname=user_42["last_name"],
                username=user_42["login"],
                email=user_42["email"],
                avatarURI=user_42["image"]["link"],
                intra_login=True
            )
            created_new = True
        access_token = generate_access_token(user_db)
        refresh_token = generate_refresh_token(user_db)
        dto = auth_dto(user_db, access_token, refresh_token)
        return JsonResponse(dto, status=201 if created_new else 200)
    return HttpResponseForbidden(json.dumps({"message": "code is invalid", "response": response}), content_type='application/json')


@require_http_methods(['POST'])
@request_body(
    content_type="application/json",
    fields={
        "name": str_field(max_length=25, required=True),
        "surname": str_field(max_length=25, required=True),
        "username": str_field(min_length=9, required=True),
        "email": str_field(required=True, max_length=50),
        "password": str_field(required=True)
    }
)
def sign_up(request: HttpRequest, content: dict) -> HttpResponse:
    usernamecheck = UserModel.objects.filter(username__exact=content.get("username"), email__exact=content.get("email"))
    if usernamecheck.exists():
        return HttpResponseBadRequest(json.dumps({"message": "Username has already taken."}), content_type="application/json")
    password_hasher = BCryptPasswordHasher()
    encoded_password = password_hasher.encode(content["password"], password_hasher.salt())
    user = UserModel.objects.create(
        name=content["name"],
        surname=content["surname"],
        username=content['username'],
        email=content['email'],
        avatarURI="http://localhost/api/media/default.jpeg",
        password=encoded_password,
        intra_login=False
    )
    access_token = generate_access_token(user)
    refresh_token = generate_refresh_token(user)
    return JsonResponse(auth_dto(user, access_token, refresh_token), status=201)


@require_http_methods(['POST'])
@authorize()
def sign_out(request: HttpRequest) -> HttpResponse:
    return JsonResponse({"message": "Not Supported Yet."}, status=500)


@require_http_methods(['GET'])
@authorize()
def verify_token(request):
    dto = request.auth_info.token_info
    return JsonResponse(dto, status=200)


@require_http_methods(['GET'])
@authorize(token_type="refresh")
def refresh_token(request: HttpRequest) -> HttpResponse:
    auth_info = getattr(request, "auth_info")
    user = auth_info.user
    access_token = generate_access_token(user)
    refresh_token = getattr(auth_info, "token")
    return JsonResponse(auth_dto(user, access_token, refresh_token), status=200)