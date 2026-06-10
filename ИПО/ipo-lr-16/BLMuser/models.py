from django.db import models
from django.contrib.auth.models import AbstractUser

class BLMusers(AbstractUser):
    groups = models.ManyToManyField(
         'auth.Group',
        related_name='belucontrol_users'
    )

    user_permissions = models.ManyToManyField(
        'auth.Permission',
        related_name='belucontrol_users',
    )

