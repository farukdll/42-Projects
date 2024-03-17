from django.db import models
from trascendence.api.models.SerializableModel import SerializableModel
from trascendence.api.models import UserModel
from trascendence.api.models.shared_functions import id_generator
from .Tournaments import Tournaments
import uuid


class TournamentInvitations(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    target_user = models.ForeignKey(UserModel, related_name="%(class)s_target_user", on_delete=models.CASCADE)
    tournament = models.ForeignKey(Tournaments, related_name="%(class)s_tournament_id", on_delete=models.CASCADE)
    invite_code = models.CharField(max_length=6, default=id_generator)
    message = models.CharField(max_length=400)
