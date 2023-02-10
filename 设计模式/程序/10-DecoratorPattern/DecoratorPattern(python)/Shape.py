import abc

# 形状基类
class Shape(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def draw(self):
        pass

# 具体实现类
class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def draw(self):
        print("Draw a Circle with", self.radius, "radius")


class Rectangle(Shape):
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def draw(self):
        print("Draw a Rectangle with", self.length, "length and", self.width, "width")
 
# 继续增加形状...
