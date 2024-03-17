import random
import string
import uuid

import django.utils.timezone
from .SerializableModel import SerializableModel
from django.db import models
from trascendence.api.models import UserModel
from .shared_functions import id_generator


class Friends(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    created_at = models.DateTimeField(default=django.utils.timezone.now)
    user_pair_1 = models.ForeignKey(UserModel, related_name="%(class)s_user_pair_1", on_delete=models.CASCADE)
    user_pair_2 = models.ForeignKey(UserModel, related_name="%(class)s_user_pair_2", on_delete=models.CASCADE)


class FriendInvitation(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    created_at = models.DateTimeField(default=django.utils.timezone.now)
    origin = models.ForeignKey(UserModel, related_name="%(class)s_origin", on_delete=models.CASCADE)
    target = models.ForeignKey(UserModel, related_name="%(class)s_target", on_delete=models.CASCADE)
    invite_code = models.CharField(max_length=6, default=id_generator)
    note = models.CharField(max_length=400)


class BlackList(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    created_at = models.DateTimeField(default=django.utils.timezone.now)
    issuer = models.ForeignKey(UserModel, related_name="%(class)s_issuer", on_delete=models.CASCADE)
    user = models.ForeignKey(UserModel, related_name="%(class)s_user", on_delete=models.CASCADE)

