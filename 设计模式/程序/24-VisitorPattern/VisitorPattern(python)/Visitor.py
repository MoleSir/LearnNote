import abc

# 访问者基类
class ComputerPartVisitor(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def VisitKeyborad(self, keyboard):
        pass

    @abc.abstractmethod
    def VisitMonitor(self, monitor):
        pass

    @abc.abstractmethod
    def VisitMouse(self, mouse):
        pass

# 访问者的实现类，代表各种功能
# 显示功能
class ComputerPartDisplayVisitor(ComputerPartVisitor):
    def VisitKeyborad(self, keyboard):
        print("Display {0} Keyboard".format(id(keyboard)))

    def VisitMonitor(self, monitor):
        print("Display {0} Monitor".format(id(monitor)))

    def VisitMouse(self, mouse):
        print("Display {0} Mouse".format(id(mouse)))

# 修复功能
class ComputerPartFixVisitor(ComputerPartVisitor):
    def VisitKeyborad(self, keyboard):
        print("Fix {0} Keyboard".format(id(keyboard)))

    def VisitMonitor(self, monitor):
        print("Fix {0} Monitor".format(id(monitor)))

    def VisitMouse(self, mouse):
        print("Fix {0} Mouse".format(id(mouse)))