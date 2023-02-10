from Burger import *
from Pack import *
from Drink import *

# 餐类
class Meal:
    # 构造函数
    def __init__(self):
        # 创建一个数组
        self.items = []
    # 添加物体
    def AddItem(self, item):
        self.items.append(item)
    # 显示午餐
    def ShowItems(self):
        print("this meal includes:")
        for item in self.items:
            print("[Name:", item.name(), "Price:", item.price(),"Pack:", item.packing().pack(), "]")
        print("")

# builder
class MealBuilder:
    # 素食餐
    def GetVegMeal(self):
        meal = Meal()
        meal.AddItem(VegBurger())
        meal.AddItem(Coke())
        return meal
    # 肉食
    def GetNonVegMeal(self):
        meal = Meal()
        meal.AddItem(ChickenBurger())
        meal.AddItem(Pepsi())
        return meal
