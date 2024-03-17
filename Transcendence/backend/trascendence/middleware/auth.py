from django.http import HttpRequest, JsonResponse, HttpResponse, HttpResponseServerError
from trascendence.api.models.User import UserModel
from trascendence.core.token_manager import validate_token, definitions
import jwt
import traceback

def get_token(request: HttpRequest) -> str | None:
    authorization: str | None = request.headers.get("Authorization")
    if authorization is None:
        return None
    if not authorization.startswith("Bearer "):
        return None
    return authorization[len("Bearer "):]


def authorize(token_type="access"):
    def decorator(request_view):
        def middleware(request: HttpRequest, *args, **kwargs):
            token = get_token(request)
            if token is None:
                return JsonResponse({"message": "this content is not allowed"}, status=401)
            try:
                token_info = validate_token(token)
                if token_info["typ"] != token_type:
                    return JsonResponse({"message": "This token is not valid for this request."}, status=401)
                try:

                    auth_info = type('Object', (), {})()
                    if token_info["sub"] != definitions.ISSUER:
                        user = UserModel.objects.get(id=token_info['sub'])
                        setattr(auth_info, "user", user)
                    else:
                        setattr(auth_info, "sudo", True)
                    setattr(auth_info, "token_info", token_info)
                    setattr(auth_info, "token", token)
                    setattr(request, "auth_info", auth_info)
                    return request_view(request, *args, **kwargs)
                except UserModel.DoesNotExist:
                    traceback.print_exc()
                    return JsonResponse({"message": "No such user associated with this token."}, status=401)
                except:
                    traceback.print_exc()
                    return HttpResponseServerError()
            except jwt.exceptions.InvalidIssuerError:
                return JsonResponse({"message": "Token is not valid."}, status=401)
            except jwt.exceptions.ExpiredSignatureError:
                return JsonResponse({"message": "Token is expired."}, status=401)
            except jwt.exceptions.InvalidSignatureError:
                return JsonResponse({"message": "Token is not valid."}, status=401)
            except jwt.exceptions.InvalidTokenError:
                return JsonResponse({"message": f"Token couldn't verified."}, status=401)
            except:
                traceback.print_exc()
                return HttpResponseServerError()

        return middleware

    return decorator

