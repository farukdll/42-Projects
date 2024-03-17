from environ import Env

env = Env()
CLIENT_ID = env("CLIENT_42") 
CLIENT_SECRET = env("SECRET_42")
REDIRECT_URL = env("REDIRECT_URI_42")

