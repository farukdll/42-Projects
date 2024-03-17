class Notification:
    def __init__(self, audience: str, message: str, resource_group: str, resource_code: str) -> None:
        self.audience = audience
        self.message = message
        self.resource_group = resource_group
        self.resource_code = resource_code
