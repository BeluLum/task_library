from django.contrib import admin
from .models import product_category, product, game_origin, cart, cart_element

# Register your models here.
admin.site.register(product_category)
admin.site.register(product)
admin.site.register(game_origin)
admin.site.register(cart)
admin.site.register(cart_element)