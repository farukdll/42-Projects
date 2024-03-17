from environ import Env

env = Env()
SECRET = env('JWT_SECRET')
ALGORITHM = env('JWT_ALG')
ISSUER = env('JWT_ISSUER')