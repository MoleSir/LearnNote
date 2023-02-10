from Item import Item
from Pack import *

# 汉堡基类
class Burger(Item):
    # 基类汉堡只知道自己的包装是袋装
    def packing(self):
        return Wrapper()

# 具体的汉堡类
class VegBurger(Burger):
    def __init__(self):
        pass
    def name(self):
        return "Veg Burger"
    def price(self):
        return 8.0

class ChickenBurger(Burger):
    def __init__(self):
        pass
    def name(self):
        return "Chicken Burger"
    def price(self):
        return 13.5
