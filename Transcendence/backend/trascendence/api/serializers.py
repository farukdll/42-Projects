from .models.User import UserModel
from .models.SerializableModel import SerializableModel


def serialize_json(model: SerializableModel):
    return model.to_json()
