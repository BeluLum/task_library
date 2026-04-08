from django.shortcuts import render
from django.http import HttpResponse

def main_page(request):
    return render(request, 'main_page.html')

def autor_info(request):
    return render(request, 'index.html')

def lab_info(request):
    return render(request, 'info.html')
# Create your views here.
