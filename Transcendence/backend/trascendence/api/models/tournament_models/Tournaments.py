import uuid
import django.utils.timezone
from django.db import models
from django.core.validators import MaxValueValidator, MinValueValidator
from trascendence.api.models import UserModel
from trascendence.api.models.SerializableModel import SerializableModel
from trascendence.api.models.shared_functions import id_generator


class Tournaments(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    created_at = models.DateTimeField(default=django.utils.timezone.now)
    tournament_name = models.CharField(max_length=50)
    tournament_code = models.CharField(max_length=6, default=id_generator)
    created_user = models.ForeignKey(UserModel, related_name="%(class)s_created_user", on_delete=models.CASCADE)
    players_capacity = models.IntegerField(default=4, validators=[
        MaxValueValidator(8),
        MinValueValidator(4)
    ])
