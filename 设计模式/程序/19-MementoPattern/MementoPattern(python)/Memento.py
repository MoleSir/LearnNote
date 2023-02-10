# Memento 类，保持状态的类
class Memento:
    def __init__(self, state):
        self.state = state
        
    def GetState(self):
        return self.state
