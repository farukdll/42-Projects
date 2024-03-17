

def dto_notification(target, message, resource_group, resource_code):
    return {
        "type": "notification",
        "audience": target,
        "message": message,
        "resource_group": resource_group,
        "resource_code": resource_code,
    }
