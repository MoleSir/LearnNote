from Originator import Originator 
from Memento import Memento

# 创建 CareTaker 类，保存往期状态的类
class CareTaker:
    def __init__(self):
        # 保存之前的所有备忘录
        self.mementos = []

    def Add(self, memento):
        self.mementos.append(memento)

    def Get(self, index):
        return self.mementos[index]