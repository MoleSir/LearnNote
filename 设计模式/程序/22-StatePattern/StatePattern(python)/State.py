import abc

# 基类
class State(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def DoOperation1(self, message):
        pass
    @abc.abstractmethod
    def DoOperation2(self, message):
        pass
    @abc.abstractmethod
    def DoOperation3(self, message):
        pass

# 实现类
class StateA(State):
    def __init__(self):
        pass
    def DoOperation1(self, message):
        print("Do Operation1 at State A with {0}".format(message))
    def DoOperation2(self, message):
        print("Do Operation2 at State A with {0}".format(message))
    def DoOperation3(self, message):
        print("Do Operation3 at State A with {0}".format(message))

class StateB(State):
    def __init__(self):
        pass
    def DoOperation1(self, message):
        print("Do Operation1 at State B with {0}".format(message))
    def DoOperation2(self, message):
        print("Do Operation2 at State B with {0}".format(message))
    def DoOperation3(self, message):
        print("Do Operation3 at State B with {0}".format(message))

class StateC(State):
    def __init__(self):
        pass
    def DoOperation1(self, message):
        print("Do Operation1 at State C with {0}".format(message))
    def DoOperation2(self, message):
        print("Do Operation2 at State C with {0}".format(message))
    def DoOperation3(self, message):
        print("Do Operation3 at State C with {0}".format(message))