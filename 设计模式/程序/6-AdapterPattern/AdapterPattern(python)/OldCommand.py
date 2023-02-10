import abc

# 旧的接口
class OldCommand(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def work(self, arg):
        pass
    
# 旧接口的实现类
class OldFork(OldCommand):
    def work(self, arg):
        print("fork process named:", arg, "with old method")

class OldKill(OldCommand):
    def work(self, arg):
        print("kill process named:", arg, "with old method")


