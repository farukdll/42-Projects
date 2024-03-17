import traceback
import json
from django.views.decorators.http import require_http_methods
from django.http import HttpRequest, HttpResponseNotFound, JsonResponse, HttpResponse, HttpResponseServerError
from django.db.models import Q
from trascendence.middleware.validators import request_body, str_field
from trascendence.middleware.auth import authorize
from trascendence.api.models.tournament_models import Tournaments
from trascendence.api.models.User import UserModel
from trascendence.api.models.match_models import Matches
from trascendence.api.models.tournament_models import TournamentMatches
from django.contrib.auth.hashers import BCryptPasswordHasher
from trascendence.api.dto import user_dto, profile_dto

#TODO: Look at get most played matches. there is a possibility that causes a bug
def get_most_played(user_id_list):
    from collections import Counter
    most_played_with = Counter(user_id_list)
    return most_played_with.most_common(2)[1][0]


@require_http_methods(['GET'])
def get_user_profile(request: HttpRequest, username: str):
    try:
        user = UserModel.objects.get(Q(username__exact=username))
        matches = Matches.objects.filter((Q(home=user) | Q(away=user)) & Q(is_played=True))
        tournament_matches = Matches.objects.filter((Q(home=user) | Q(away=user)) & Q(is_played=True)).exclude(tournament=None)
        tournaments = Tournaments.objects.filter(tournamentplayers_tournament_id__user=user.id)
        played_users = [match.home.id for match in matches] + [match.away.id for match in matches]
        rival = None
        if len(played_users) > 0:
            rival_id = get_most_played(played_users)
            rival = UserModel.objects.get(id=rival_id)
        profile = profile_dto(user, matches, tournament_matches, tournaments, rival)
        return JsonResponse(profile, status=200)
    except UserModel.DoesNotExist:
        return HttpResponseNotFound("User not found")
    except Exception as e:
        traceback.print_exc()
        return HttpResponseServerError(str(e))
    
@require_http_methods(['PATCH'])
@authorize()
@request_body(
    content_type="application/json",
    fields={
        "username": str_field(required=False),
        "name": str_field(required=False),
        "surname": str_field(required=False),
        "email": str_field(required=False),
        "avatarURI": str_field(required=False),
        "playcode": str_field(required=False),
        "password": str_field(required=False)
    }
)
def update_profile(request: HttpRequest, content: dict):
    user = request.auth_info.user
    password_hasher = BCryptPasswordHasher()
    if "username" in content.keys():
        user.username = content["username"]

    if "name" in content.keys():
        user.name = content["name"]

    if "surname" in content.keys():
        user.surname = content["surname"]

    if "email" in content.keys():
        user.email = content["email"]

    if "avatarURI" in content.keys():
        user.avatarURI = content["avatarURI"]

    if "playcode" in content.keys():
        user.play_code = password_hasher.encode(content["playcode"], password_hasher.salt())
        user.has_play_code = True

    if "password" in content.keys():
        user.password = password_hasher.encode(content["password"], password_hasher.salt())

    user.save()
    return JsonResponse({"new_user": user_dto(user)})

