from django import forms
from django.contrib.auth.forms import UserCreationForm, UserChangeForm
from .models import CustomUser

class BLMusersCreationForm(UserCreationForm):

    class Meta(UserCreationForm):
        model = CustomUser
        fields = ('username', 'email')

class BLMusersChangeForm(UserChangeForm):

    class Meta:
        model = BLMusers
        fields = ('username', 'email')