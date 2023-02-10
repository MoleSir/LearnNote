from AbstractFactory import *

# 创建工厂生产者
factoryProducer = FactoryProducer()

# 创建形状工厂
shapeFactory = factoryProducer.GetFactory("Shape")
# 创建颜色工厂
colorFactory = factoryProducer.GetFactory("Color")
# 创建笔工厂
penFactory = factoryProducer.GetFactory("Pen")

# 使用工厂
circle = shapeFactory.GetShape("Circle")
circle.draw()
red = colorFactory.GetColor("Red")
red.fill()
