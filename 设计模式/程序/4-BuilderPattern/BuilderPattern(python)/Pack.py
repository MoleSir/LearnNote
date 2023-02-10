import abc

# 包装基类
class Pack(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def pack(self):
        pass

# 包装实现
class Wrapper(Pack):
    def __init__(self):
        pass
    def pack(self):
        return "Wrapper"

class Bottle(Pack):
    def __init__(self):
        pass
    def pack(self):
        return "Bottle"