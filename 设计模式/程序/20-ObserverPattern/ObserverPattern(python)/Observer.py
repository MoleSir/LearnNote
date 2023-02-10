import abc

# 观察者基类
class Observer(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def Uptate(self, newState):
        pass

# 观察者实现
class BinaryObserver(Observer):
    def __init__(self):
        pass
    def Uptate(self, newState):
        print('Binary String: {0}'.format(bin(newState)))

class OctalObserver(Observer):
    def __init__(self):
        pass
    def Uptate(self, newState):
        print('Octal String: {0}'.format(oct(newState)))

class HexaObserver(Observer):
    def __init__(self):
        pass
    def Uptate(self, newState):
        print('Hexa String: {0}'.format(hex(newState)))