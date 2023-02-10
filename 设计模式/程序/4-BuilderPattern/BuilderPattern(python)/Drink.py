from Item import Item
from Pack import *

# 饮料基类
class Drink(Item):
    # 饮料基类只知道自己瓶装的
    def packing(self):
        return Bottle()

# 饮料实现
class Coke(Drink):
    def __init__(self):
        pass
    def name(self):
        return "Coke"
    def price(self):
        return 4.0

class Pepsi(Drink):
    def __init__(self):
        pass
    def name(self):
        return "Pepsi"
    def price(self):
        return 3.5