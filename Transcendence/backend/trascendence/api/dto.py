from trascendence.api.models import (
    UserModel,
    Friends,
    FriendInvitation,
    BlackList,
    TournamentInvitations,
    TournamentMatches,
    TournamentPlayers,
    Tournaments,
    Matches,
    Uploads
)


# User Dto
def user_dto(usermodel: UserModel) -> dict:
    return {
        "id": str(usermodel.id),
        "name": usermodel.name,
        "surname": usermodel.surname,
        "name_surname": f"{usermodel.name} {usermodel.surname}",
        "username": usermodel.username,
        "email": usermodel.email,
        "avatarURI": usermodel.avatarURI,
        "has_playcode": usermodel.has_play_code
    }


# user list dto
def create_user_list(users: list[UserModel]) -> dict:
    response = dict()
    response["length"] = len(users)
    response["users"] = [user_dto(user) for user in users]
    return response


# Friend dto
def friend_dto(friend: Friends) -> dict:
    return {
        "id": str(friend.id),
        "pair_1": user_dto(friend.user_pair_1),
        "pait_2": user_dto(friend.user_pair_2)
    }


# Friend Invitation
def friend_invitation_dto(invitaion: FriendInvitation) -> dict:
    return {
        "id": str(invitaion.id),
        "from": user_dto(invitaion.origin),
        "to": user_dto(invitaion.target),
        "invite_code": invitaion.invite_code,
        "note": invitaion.note
    }


# Blacklist
def blacklist_dto(blacklist: BlackList) -> dict:
    return {
        "id": str(blacklist.id),
        "blocked_by": user_dto(blacklist.issuer),
        "user": user_dto(blacklist.user)
    }


# Tournament
def tournament_dto(tournament: Tournaments, players: list[TournamentPlayers] | None = None) -> dict:
    dto = {
        "id": str(tournament.id),
        "name": tournament.tournament_name,
        "tournament_code": tournament.tournament_code,
        "created_by": user_dto(tournament.created_user),
        "create_date": tournament.created_at.isoformat()
    }
    if players is not None:
        dto["players"] = {
            "length": len(players),
            "content": [tournament_player_dto(player) for player in players]
        }
    return dto


# Tournament Invitation
def tournament_invitation_dto(invitation: TournamentInvitations) -> dict:
    return {
        "id": str(invitation.id),
        "to": user_dto(invitation.target_user),
        "from": user_dto(invitation.tournament.created_user),
        "invite_code": invitation.invite_code,
        "note": invitation.message
    }


# Tournament Player
def tournament_player_dto(player: TournamentPlayers) -> dict:
    return {
        "id": str(player.id),
        "user": user_dto(player.user),
        "tournament": tournament_dto(player.tournament),
        "stage": player.stage,
        "has_pair": player.has_pair,
        "pair_user": user_dto(player.pair_user) if player.pair_user is not None else None
    }


# Tournament Matches
def tournament_match_dto(match: TournamentMatches) -> dict:
    return {
        "id": str(match.id),
        "match": match_dto(match.match),
        "match_degree": match.match_priority
    }


# Matches
def match_dto(match: Matches) -> dict:
    return {
        "id": str(match.id),
        "tournament": tournament_dto(match.tournament) if match.tournament is not None else None,
        "match_code": match.match_code,
        "home": {
            "user": user_dto(match.home),
            "score": match.score_home,
            "signature": match.home_signature
        },
        "away": {
            "user": user_dto(match.away),
            "score": match.score_away,
            "signaure": match.away_signature
        },
        "played_time": match.played_time.isoformat() if match.played_time is not None else "",
    }


# Uploads
def uploads_dto(upload: Uploads) -> dict:
    return {
        "id": str(upload.id),
        "name": upload.name,
        "extension": upload.extension,
        "full_name": f"{upload.name}.{upload.extension}",
        "created_at": upload.created_at,
        "owner": user_dto(upload.owner)
    }


# Auth dto
def auth_dto(usermodel: UserModel, access_token: str, refresh_token: str | None = None) -> dict:
    return {
        "user": user_dto(usermodel),
        "access_token": access_token,
        "refresh_token": refresh_token if refresh_token is not None else None
    }


# Profile dto
def profile_dto(user: UserModel, matches: list[Matches], tournament_matches: list[Matches], tournaments: list[Tournaments], rival: UserModel | None) -> dict:
    return {
        "user": user_dto(user),
        "matches": list_dto([match_dto(match) for match in matches]),
        "tournament_matches": list_dto([match_dto(match) for match in tournament_matches]),
        "tournaments": list_dto([tournament_dto(tournament) for tournament in tournaments]),
        "rival": user_dto(rival) if rival is not None else None
    }


# Other types
def list_dto(dto_list: list) -> dict:
    return {
        "length": len(dto_list),
        "content": dto_list
    }