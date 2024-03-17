from .Notification import Notification
import requests
import json

NOTIFICATION_APP_NAME = "http://websocket:8000"

def push_notification(notification: Notification, auth_token: str):
    url = f"{NOTIFICATION_APP_NAME}/ws/api/push/{notification.audience}"
    headers = {
        "Content-Type": "application/json",
        "Authorization": f"Bearer {auth_token}"
    }
    datas = {
        "message": notification.message,
        "resource_group": notification.resource_group,
        "resource_code": notification.resource_code
    }
    try:
        response = requests.post(url=url, headers=headers, data=json.dumps(datas))
        if response.ok:
            return True
        return False
    except:
        import traceback
        traceback.print_exc()
        return False
