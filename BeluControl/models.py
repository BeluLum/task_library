from django.db import models
from django.contrib.auth.models import AbstractUser

class User(AbstractUser):
    pass


class product_category(models.Model):
    Name = models.CharField(max_length=100, help_text='Название категории')
    Description = models.TextField()

    def __str__(self):
        return self.Name

class product(models.Model):
    Name = models.CharField(max_length=200, help_text='Название товара')
    Description = models.TextField()
    Product_Photo = models.ImageField()
    Value = models.DecimalField(decimal_places=2, max_digits=10)
    Quantity_in_stock = models.IntegerField()
    Category = models.ForeignKey('product_Category', on_delete=models.CASCADE)
    Origin = models.ForeignKey('game_origin', on_delete=models.CASCADE)


    def __str__(self):
        return self.Name
    

class game_origin(models.Model):
    Name = models.CharField(max_length=100, help_text='Название игры')


    def __str__(self):
        return self.Name

class cart(models.Model):
    Userr = models.OneToOneField(User, on_delete=models.CASCADE)
    CreationDate =  models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"Корзина пользователя {self.Userr}"

    def total_value(self):
        return cart_element.Quantity_in_cart * product.Value
    #?????????????

class cart_element(models.Model):
    Cart = models.ForeignKey(cart, on_delete=models.CASCADE)
    Product = models.ForeignKey(product, on_delete=models.CASCADE)
    Quantity_in_cart = models.PositiveIntegerField()
    def __str__(self):
        return str(self.Product)
    def element_value(self):
        if self.Quantity_in_cart > product.Quantity_in_stock:
            return "что-то возвращает я хз что"
        else:
            return self.Quantity_in_cart * product.Value

