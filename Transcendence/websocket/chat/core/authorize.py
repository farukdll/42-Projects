import requests

AUTHORIZER_URL = "http://backend:8000/api/auth/token"

def authorize_token(token):
    if not token:
        return {"error": "Token is required"}
    
    response = requests.get(AUTHORIZER_URL, data={"token": token})

    if response.status_code == 200:
        #token okki, kullanıcı bilgilerini döndürür
        return response.json()
    else:
        return {"error": "Invalid token"}