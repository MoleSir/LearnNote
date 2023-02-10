import abc

class Operation(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def Operate(self, num1, num2):
        pass

class AddOperation(Operation):
    def __init__(self):
        pass
    def Operate(self, num1, num2):
        return num1 + num2

class SubOperation(Operation):
    def __init__(self):
        pass
    def Operate(self, num1, num2):
        return num1 - num2

class MulOperation(Operation):
    def __init__(self):
        pass
    def Operate(self, num1, num2):
        return num1 * num2