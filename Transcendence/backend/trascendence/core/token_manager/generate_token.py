
from datetime import timedelta, datetime
import jwt
import uuid
from .definitions import ISSUER, SECRET, ALGORITHM
from .token_types import TYPE_ACCESS, TYPE_REFRESH, TYPE_SIGNATURE_MATCH

def generate_token(extended_payload: dict, expiration_time = timedelta(minutes=10)) -> str:
    payload = {
        "jti": str(uuid.uuid4()),
        "iss": ISSUER,
        "iat": datetime.now(),
		"nbf": datetime.now(),
        "exp": int((datetime.now() + expiration_time).timestamp())
    }
    payload.update(extended_payload)
    encoded_jwt = jwt.encode(payload, SECRET, algorithm=ALGORITHM)
    return encoded_jwt


def generate_access_token(user) -> str:
    return generate_token({"sub": str(user.id), "typ": TYPE_ACCESS}, timedelta(hours=2))


def generate_refresh_token(user) -> str:
    return generate_token({"sub": str(user.id), "typ": TYPE_REFRESH}, timedelta(days=2))


def generate_match_token(user) -> str:
    payload = {
        "sub": str(user.id),
        "typ": TYPE_SIGNATURE_MATCH
    }
    return generate_token(payload, timedelta(minutes=45))


def generate_sudo_token() -> str:
    return generate_token({"sub": ISSUER, "typ": TYPE_ACCESS}, timedelta(seconds=30))