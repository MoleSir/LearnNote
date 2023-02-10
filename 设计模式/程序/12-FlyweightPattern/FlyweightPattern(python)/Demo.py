# python 实现享元模式
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
        # 字典
        self.shapeDict = {}

    def GetShape(self, shapeType):
        # 检查是否存在 
        if shapeType in self.shapeDict.keys():
            print("Use Object already created")
            return self.shapeDict[shapeType]

        # 不存在需要创建
        shape = None
        if shapeType == 'Circle':
            shape = Circle()
        elif shapeType == 'Rectangle':
            shape = Rectangle()
        elif shapeType == 'Square':
            shape = Square()
        else:
            print("The Factory can't create shapeType")
        
        # 添加对象
        if shape != None:
            self.shapeDict[shapeType] = shape

        return shape


# 创建工厂
shapeFactory = ShapeFactory()

# 获得形状
circle = shapeFactory.GetShape('Circle')
rectangle = shapeFactory.GetShape('Rectangle')
square = shapeFactory.GetShape('Square')
circle1 = shapeFactory.GetShape('Circle')

print("circle == circle1 ? {0}".format(circle == circle1))

circle.draw()
rectangle.draw()
square.draw()