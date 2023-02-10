from ShapeFactory import *
from ColorFactory import *

class FactoryProducer(object):
    def __init__(self):
        pass

    def GetFactory(self, factoryType):
        if factoryType == "Color":
            return ColorFactory()
        elif factoryType == "Shape":
            return ShapeFactory()
        else:
            print("No", factoryType, "factory")
            return None


