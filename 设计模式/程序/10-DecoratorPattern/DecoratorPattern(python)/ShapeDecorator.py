from Shape import *

# 形状的装饰器基类
class ShapeDecorator(Shape):
    @abc.abstractmethod
    def __init__(self, shape):
        self.shape = shape
    

# 装饰器实现类
class ColorShape(ShapeDecorator):
    def __init__(self, shape, color):
        ShapeDecorator.__init__(self, shape)
        self.color = color
    # 实现接口
    def draw(self):
        # 除了原来的绘画功能，还增加了颜色
        self.shape.draw()
        print("fill with", self.color, "color")

# 还可以继续拓展别的形状装饰器...