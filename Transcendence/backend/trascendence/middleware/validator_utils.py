
import json
from typing import Callable, Any


def json_parser(content: str | bytes) -> dict | None:
    try:
        return json.loads(content)
    except json.decoder.JSONDecodeError as error:
        return None


def validate_content(content: dict[str, Any], fields: dict[str, Callable[[Any], bool]]):
    for field in fields.keys():
        if isinstance(fields[field], dict):
            if not isinstance(content[field], dict):
                raise Exception(f"The type of '{field}' does not match with definition")
            validate_content(content[field], fields[field])
        elif not fields[field](content.get(field, None)):
            raise Exception(f"The field '{field}' is not a valid value")
    return True


def validator(checklist: list[Callable[[Any], bool]], required: bool) -> Callable[[Any], bool]:
    def wrapper(field: Any) -> bool:
        if field is not None:
            for check in checklist:
                if not check(field):
                    return False
            return True
        else:
            return not required

    return wrapper
