from OldCommand import *
from NewCommand import *

# 适配器，让旧功能可以使用新接口
class ForkAdapter(NewCommand):
    def __init__(self):
        # 内部拥有一个旧接口对象
        self.oldFork = OldFork()
    
    # 实现基类的接口
    def excute(self, arg):
        # 调用内部的旧接口
        self.oldFork.work(arg)

class KillAdapter(NewCommand):
    def __init__(self):
        self.oldKill = OldKill()
    def excute(self, arg):
        self.oldKill.work(arg)