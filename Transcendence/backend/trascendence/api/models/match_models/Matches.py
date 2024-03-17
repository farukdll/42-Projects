import django.utils.timezone
from django.db import models
from trascendence.api.models.shared_functions import id_generator
from trascendence.api.models.SerializableModel import SerializableModel
from trascendence.api.models import UserModel
from trascendence.api.models.tournament_models.Tournaments import Tournaments
import uuid

class Matches(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    match_code = models.CharField(max_length=6, default=id_generator)
    tournament = models.ForeignKey(Tournaments, related_name="%(class)s_tournament_id", on_delete=models.CASCADE, blank=True, null=True)
    home = models.ForeignKey(UserModel, related_name="%(class)s_home", on_delete=models.CASCADE)
    score_home = models.IntegerField(default=0)
    away = models.ForeignKey(UserModel, related_name="%(class)s_away", on_delete=models.CASCADE)
    score_away = models.IntegerField(default=0)
    winner = models.ForeignKey(UserModel, related_name="%(class)s_winner", on_delete=models.CASCADE, blank=True, null=True, default=None)
    is_played = models.BooleanField(default=False)
    home_signature = models.CharField(blank=True, null=True, default=None)
    away_signature = models.CharField(blank=True, null=True, default=None)
    played_time = models.DateTimeField(blank=True, null=True, default=None)
    created_time = models.DateTimeField(default=django.utils.timezone.now)
