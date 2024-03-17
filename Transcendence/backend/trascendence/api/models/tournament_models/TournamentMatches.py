import django.utils.timezone
from django.db import models
from trascendence.api.models.match_models import Matches
from trascendence.api.models.SerializableModel import SerializableModel
import uuid
from django.core.validators import MaxValueValidator, MinValueValidator


class TournamentMatches(models.Model, SerializableModel):
    id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
    match = models.ForeignKey(Matches, related_name="%(class)s_match_id", on_delete=models.CASCADE)
    match_priority = models.IntegerField(validators=[
        MaxValueValidator(3),
        MinValueValidator(1)
    ])
