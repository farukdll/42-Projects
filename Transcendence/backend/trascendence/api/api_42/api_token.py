import requests

from .definitions import *
def get_42_token(code: str) -> dict:
    return_dict = dict()
    url = "https://api.intra.42.fr/oauth/token"
    data = {
        "grant_type": "authorization_code",
        "client_id": CLIENT_ID,
        "client_secret": CLIENT_SECRET,
        "code": code,
        "redirect_uri": REDIRECT_URL
    }
    headers = {
        "Content-Type": "application/x-www-form-urlencoded"
    }
    response = requests.post(url, data=data, headers=headers)
    if response.ok:
        return_dict["ok"] = True
    else:
        import sys
        print("input code:", code, file=sys.stderr)
        print("Token couldnt fetched. Reason is:\n" + response.text, file=sys.stderr)
        return_dict["ok"] = False
    return_dict["content"] = response.json()
    return return_dict