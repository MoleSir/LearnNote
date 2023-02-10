from OldCommand import *
from NewCommand import *
from Adapter import *

# 直接使用新接口
newFork = NewFork()
newFork.excute("Hello")
newKill = NewKill()
newKill.excute("Hello")

# 通过适配器使用旧接口
oldFork = ForkAdapter()
oldFork.excute("World")
oldKill = KillAdapter()
oldKill.excute("World")

# 使用了适配器后，新旧接口都成为了新接口的子类，可以作为一个工厂的产品使用