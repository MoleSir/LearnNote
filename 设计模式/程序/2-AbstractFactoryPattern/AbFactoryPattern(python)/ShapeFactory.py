import abc
# 基类
class Shape(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def draw(self):
        pass

# 实现类
class Circle(Shape):
    def __init__(self):
        print("Create a Circle!")
    def draw(self):
        print("Draw a Circle!")

class Rectangle(Shape):
    def __init__(self):
        print("Create a Rectangle!")
    def draw(self):
        print("Draw a Rectangle!")
    
class Square(Shape):
    def __init__(self):
        print("Create a Square!")
    def draw(self):
        print("Draw a Square!")


# 工厂
class ShapeFactory(object):
    def __init__(self):
        print("Create a Shape Factory")

    def GetShape(self, shapeType):
        if shapeType == "Circle":
            return Circle()
        elif shapeType == "Rectangle":
            return Rectangle()
        elif shapeType == "Square":
            return Square()
        else:
            print("The Factory can't create", shapeType)
            return None
            
    def GetColor(self, colorType):
        return None
    