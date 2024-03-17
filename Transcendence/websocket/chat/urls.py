from django.urls import path
from . import views 

urlpatterns = [
    path('ws/api/push/<username>', views.push_notification),
    path('', views.lobby)
]