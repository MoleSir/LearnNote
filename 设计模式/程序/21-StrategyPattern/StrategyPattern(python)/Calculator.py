from Operations import *

class Calculator:
    def __init__(self, operation):
        self.operation = operation
    
    def Calculate(self, num1, num2):
        return self.operation.Operate(num1, num2)

    def SetOperation(self, operation):
        self.operation = operation

