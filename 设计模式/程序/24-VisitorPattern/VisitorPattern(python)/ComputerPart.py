import abc

# 电脑部件基类
class ComputerPart(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def Accept(self, visitor):
        pass

# 电脑部件子类
class Keyboard(ComputerPart):
    def Accept(self, visitor):
        visitor.VisitKeyborad(self)

class Monitor(ComputerPart):
    def Accept(self, visitor):
        visitor.VisitMonitor(self)

class Mouse(ComputerPart):
    def Accept(self, visitor):
        visitor.VisitMouse(self)
