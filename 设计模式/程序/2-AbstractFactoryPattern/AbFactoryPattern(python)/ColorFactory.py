import abc
# 颜色基类
class Color(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def fill(self):
        pass

# 实现类
class Red(Color):
    def __init__(self):
        print("Create a Red")
    def fill(self):
        print("Fill with Red")

class Green(Color):
    def __init__(self):
        print("Create a Green")
    def fill(self):
        print("Fill with Green")

class Blue(Color):
    def __init__(self):
        print("Create a Blue")
    def fill(self):
        print("Fill with Blue")

# 工厂
class ColorFactory(object):
    def __init__(self):
        print("Create a Color Factory")
        
    def GetColor(self, colorType):
        if colorType == "Red":
            return Red()
        elif colorType == "Green":
            return Rectangle()
        elif colorType == "Blue":
            return Blue()
        else:
            print("The Factory can't create", shapeType)
            return None

    def GetShape(self, shapeType):
        return None
