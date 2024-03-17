class SerializableModel:
    def to_json(self):
        attrs = self.__dict__
        if '_state' in attrs:
            del attrs['_state']
        return attrs

