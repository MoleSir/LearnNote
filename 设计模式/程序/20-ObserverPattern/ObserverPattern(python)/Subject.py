# Subject 类
class Subject:
    def __init__(self, state):
        self.state = state
        self.observers = []
    
    # 改变状态
    def SetState(self, newState):
        self.state = newState
        # 触发观察者
        self.NotifyAllObservers()
    
    # 添加观察者
    def AddObserver(self, observer):
        self.observers.append(observer)

    # 触发所有观察者
    def NotifyAllObservers(self):
        for observer in self.observers:
            observer.Uptate(self.state)

    