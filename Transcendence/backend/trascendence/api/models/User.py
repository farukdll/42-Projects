import django.utils.timezone
from django.db import models
from .SerializableModel import SerializableModel
import uuid


class UserModel(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    created_at = models.DateTimeField(default=django.utils.timezone.now)
    intraId = models.IntegerField(blank=True, null=True)
    username = models.CharField(max_length=50, unique=True)
    name = models.CharField(max_length=50)
    surname = models.CharField(max_length=50)
    email = models.CharField(max_length=100, unique=True)
    avatarURI = models.CharField(max_length=200)
    password = models.CharField(max_length=72, blank=True, null=True)
    intra_login = models.BooleanField(default=False)
    user_active = models.BooleanField(default=True)
    has_play_code = models.BooleanField(default=False)
    play_code = models.CharField(max_length=72, blank=True, null=True)


