import requests


def get_user_info(token: str) -> dict:
    url = "https://api.intra.42.fr/v2/me"
    headers = {
        "Authorization": f"Bearer {token}"
    }
    response = dict()
    request = requests.get(url, headers=headers)
    if request.ok:
        response["ok"] = True
    else:
        response["ok"] = False
    response["content"] = request.json()
    return response
