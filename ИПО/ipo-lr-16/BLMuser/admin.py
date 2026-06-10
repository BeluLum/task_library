from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from .models import BLMusers

class BLMusersAdmin(UserAdmin):
    model = BLMusers
    list_display = ['email', 'username']

admin.site.register(BLMusers, BLMusersAdmin)
