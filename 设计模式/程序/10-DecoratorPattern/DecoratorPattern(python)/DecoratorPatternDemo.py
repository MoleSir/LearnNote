from Shape import *
from ShapeDecorator import *

# 直接使用形状
circle = Circle(10)
rectangle = Rectangle(3, 4)
circle.draw()
rectangle.draw()

# 使用装饰器
redCircle = ColorShape(Circle(5), "Red")
blueRectangle = ColorShape(Rectangle(8, 7), "Blue")
redCircle.draw()
blueRectangle.draw()