from Calculator import *
from Operations import *

adder = AddOperation()
subber = SubOperation()
muller = MulOperation()

calculator = Calculator(adder)
print("10 + 20 = {0}".format(calculator.Calculate(10, 20)))

calculator.SetOperation(subber)
print("20 - 15 = {0}".format(calculator.Calculate(20, 15)))

calculator.SetOperation(muller)
print("10 * 20 = {0}".format(calculator.Calculate(10, 20)))