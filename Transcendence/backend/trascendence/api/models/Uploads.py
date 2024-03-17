import django.utils.timezone
from django.db import models
from .User import UserModel
from .SerializableModel import SerializableModel
import uuid

class Uploads (models.Model, SerializableModel):
	id = models.CharField(max_length=36, default=uuid.uuid4, primary_key=True)
	name = models.CharField(max_length=50, unique=True)
	extension = models.CharField(max_length=5)
	owner = models.ForeignKey(UserModel, related_name="%(class)s_owner_id", on_delete=models.CASCADE)
	created_at = models.DateTimeField(default=django.utils.timezone.now)

