import abc

# 新的接口
class NewCommand(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def excute(self, arg):
        pass

# 新的接口
class NewFork(NewCommand):
    def excute(self, arg):
        print("fork process named:", arg, "with new fork")

class NewKill(NewCommand):
    def excute(self, arg):
        print("kill process named:", arg, "with new kill")