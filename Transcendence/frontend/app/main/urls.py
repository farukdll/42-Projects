from django.urls import path, re_path
from . import views

# http://127.0.0.1:8000/
# http://127.0.0.1:8000/index

urlpatterns =[
    re_path(r'^(?P<url>.*)$', views.home)
]