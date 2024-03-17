import jwt

from trascendence.core.token_manager.definitions import SECRET, ALGORITHM


def validate_token(token: str) -> dict:
    return jwt.decode(token, SECRET, algorithms=[ALGORITHM])