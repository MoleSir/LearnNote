from Visitor import *
from ComputerPart import *

# 创建对象
keyboard = Keyboard()
monitor = Monitor()
mouse = Mouse()
fixVisitor = ComputerPartFixVisitor()
displayVisitor = ComputerPartDisplayVisitor()

# 使用显示访问器
keyboard.Accept(displayVisitor)
monitor.Accept(displayVisitor)

# 使用修复器
mouse.Accept(fixVisitor)
monitor.Accept(fixVisitor)
keyboard.Accept(fixVisitor)
