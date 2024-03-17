from django.db import models
from django.db.models import Q

class Message(models.Model):

    author = models.CharField(max_length=36)
    audience = models.CharField(max_length=36)
    content = models.TextField()
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.author
    
    @staticmethod
    def last_10_messages(author, audience):
        return Message.objects.filter(author=author, audience=audience).order_by('-timestamp').all()[:10]
    

    @staticmethod
    def last_n_messages(author, audience, n):
        return Message.objects.filter(Q(author=author, audience=audience) | Q(author=audience, audience=author)).order_by('-timestamp').all()[:n:-1]