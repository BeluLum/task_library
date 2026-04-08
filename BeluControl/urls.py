from django.urls import path
from .views import autor_info, lab_info, main_page

urlpatterns = [
    path('', main_page, name='main_page'),
    path('autorinfo/', autor_info, name='autor_info'),
    path('labinfo/', lab_info, name='lab_info'),
]