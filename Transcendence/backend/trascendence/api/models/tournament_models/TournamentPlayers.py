from django.db import models
from trascendence.api.models.SerializableModel import SerializableModel
from trascendence.api.models import UserModel
import uuid
from .Tournaments import Tournaments


class TournamentPlayers(models.Model, SerializableModel):
    id = models.CharField(
        max_length=36,
        default=uuid.uuid4,
        primary_key=True
    )
    user = models.ForeignKey(
        UserModel,
        related_name="%(class)s_user",
        on_delete=models.CASCADE
    )
    tournament = models.ForeignKey(
        Tournaments,
        related_name="%(class)s_tournament_id",
        on_delete=models.CASCADE
    )
    has_pair = models.BooleanField(
        default=False
    )
    pair_user = models.ForeignKey(
        UserModel,
        related_name="%(class)s_pair_user",
        on_delete=models.CASCADE,
        blank=True,
        null=True,
        default=None
    )
    stage = models.IntegerField(default=1)
