import json
from django.views.decorators.http import require_http_methods
from django.http import HttpRequest, HttpResponse, JsonResponse, HttpResponseNotFound, HttpResponseForbidden
from trascendence.middleware.auth import authorize
from trascendence.api.models import Matches, UserModel, TournamentPlayers
from django.db.models import Q
from trascendence.core import validate_token
from trascendence.middleware.validators import request_body, str_field, number_field
from trascendence.api.dto import match_dto, user_dto
from trascendence.core.token_manager import validate_token
from django.utils.timezone import now
from trascendence.core.token_manager import token_types, generate_match_token
from django.contrib.auth.hashers import BCryptPasswordHasher
import traceback


@require_http_methods(['GET'])
@authorize()
def get_matches_for_user(request: HttpRequest, username: str):
    matches = Matches.objects.filter((Q(home__username=username) | Q(away__username=username)) & Q(is_played=True))
    matches_list = [match_dto(match) for match in matches]
    return JsonResponse({"length": len(matches_list), "matches": matches_list}, status=200)


@require_http_methods(['GET'])
@authorize()
def get_matches_for_users(request: HttpRequest, user1: str, user2: str):
    matches = Matches.objects.filter((Q(home__username=user1) & Q(away__username=user2)) |
                                     (Q(home__username=user2) & Q(away__username=user1))).filter(is_played=True)
    matches_list = [match_dto(match) for match in matches]
    return JsonResponse({"length": len(matches_list), "matches": matches_list}, status=200)


@require_http_methods(['POST'])
@request_body(
    content_type="application/json",
    fields={
        "home": {
            "score": number_field(required=True),
            "token": str_field(required=True)
        },
        "away": {
            "score": number_field(required=True),
            "token": str_field(required=True)
        }
    }
)
def submit_matches_for_users(request: HttpRequest, content):
    token_home = content["home"]["token"]
    token_away = content["away"]["token"]
    score_home = content["home"]["score"]
    score_away = content["away"]["score"]
    try:
        valid_home = validate_token(token_home)
        valid_away = validate_token(token_away)
        user_home = UserModel.objects.get(id=valid_home["sub"])
        user_away = UserModel.objects.get(id=valid_away["sub"])
        saved_match = Matches.objects.create(
            home=user_home,
            away=user_away,
            score_home=score_home,
            score_away=score_away,
            winner=(user_away if score_away > score_home else user_home),
            is_played=True,
            home_signature=token_home,
            away_signature=token_away
        )
        return JsonResponse({"message":"Match saved", "content": match_dto(saved_match)}, status=201)
    except:
        import traceback
        traceback.print_exc()
        return HttpResponseForbidden("Not allowed")


@require_http_methods(['POST'])
@request_body(
    content_type="application/json",
    fields={
        "home": {
            "score": number_field(required=True),
            "token": str_field(required=True)
        },
        "away": {
            "score": number_field(required=True),
            "token": str_field(required=True)
        }
    }
)
def submit_planned_match(request: HttpRequest, matchcode, content) -> HttpResponse:
    try:
        planned_match = Matches.objects.get(match_code=matchcode, is_played=False)
        home = planned_match.home
        away = planned_match.away
        home_token_verified = validate_token(content["home"]["token"])
        away_token_verified = validate_token(content["away"]["token"])
        if home_token_verified["sub"] != str(home.id) or away_token_verified["sub"] != str(away.id):    
            return HttpResponseForbidden()
        score_home = content["home"]["score"]
        score_away = content["away"]["score"]
        winner = away if score_away > score_home else home
        loser = home if score_away > score_home else away
        planned_match.score_home = score_home
        planned_match.home_signature = content["home"]["token"]
        planned_match.score_away = score_away
        planned_match.away_signature = content["away"]["token"]
        planned_match.is_played = True
        planned_match.played_time = now()
        planned_match.winner = winner
        planned_match.save()
        if planned_match.tournament is not None:
            try:
                tournament = planned_match.tournament
                tournament_player_winner = TournamentPlayers.objects.get(tournament=tournament, user=winner)
                tournament_player_winner.stage += 1
                tournament_player_winner.has_pair = False
                tournament_player_winner.pair_user = None
                next_player = TournamentPlayers.objects.filter(
                    tournament=tournament, 
                    stage=tournament_player_winner.stage,
                    has_pair=False).first()
                if next_player is not None:
                    tournament_player_winner.pair_user = next_player.user
                    tournament_player_winner.has_pair = True
                    next_player.pair_user = tournament_player_winner.user
                    next_player.has_pair = True
                    next_player.save()
                tournament_player_winner.save()
                tournament_player_loser = TournamentPlayers.objects.get(tournament=tournament, user=loser)
                tournament_player_loser.has_pair = False
                tournament_player_loser.save()
            except TournamentPlayers.DoesNotExist:
                import sys
                print("TOURNAMENT_PLAYER COULDN'T UPDATED", file=sys.stderr)
                traceback.print_exc()
        return JsonResponse({"message": "match saved"}, status=200)
    except Matches.DoesNotExist:
        return HttpResponseNotFound(json.dumps({"message": "No such match"}), content_type="application/json")


@require_http_methods(['GET'])
def get_planned_match(request: HttpRequest, matchcode):
    try:
        planned_match = Matches.objects.get(match_code = matchcode)
        return JsonResponse(match_dto(planned_match))
    except Matches.DoesNotExist:
        return HttpResponseNotFound()


@require_http_methods(['POST'])
@request_body(
    content_type="application/json",
    fields= {
        "username": str_field(required=True),
        "playcode": str_field(required=True)
    }
)
def verify_playcode(request: HttpRequest, content: dict) -> HttpResponse:
    password_hasher = BCryptPasswordHasher()
    username = content["username"]
    password_raw = content["playcode"]
    user = UserModel.objects.filter(username=username).first()
    if user is not None:
        if not user.has_play_code:
            return HttpResponseForbidden()
        if password_hasher.verify(password_raw, user.play_code):
            match_token = generate_match_token(user)
            return JsonResponse({"user": user_dto(user), "token": match_token}, status=200)
        return HttpResponseForbidden()
    return HttpResponseNotFound()