import abc

# 物品基类
class Item(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def name(self):
        pass
    
    @abc.abstractmethod
    def price(self):
        pass

    @abc.abstractmethod
    def packing(self):
        pass