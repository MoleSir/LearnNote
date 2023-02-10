from Memento import *

# 创建 Originator 类，需要版本控制的类
class Originator:
    def __init__(self):
        self.state = ""

    def GetState(self):
        return self.state

    def SetState(self, newState):
        self.state = newState

    # 获取当前状态，保存到一个备忘录中
    def SaveStateToMemento(self):
        return Memento(self.state)

    # 从一个备忘录中恢复数据
    def GetStateFromMemento(self, memento):
        self.state = memento.GetState()