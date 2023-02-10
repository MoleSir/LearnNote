import abc

class Game(metaclass = abc.ABCMeta):
    # 抽象函数，需要子类重写
    @abc.abstractmethod
    def Initial(self):
        pass
    @abc.abstractmethod
    def PlayGame(self):
        pass
    @abc.abstractmethod
    def EndGame(self):
        pass

    # 不需要重写的流程
    def ShowPoint(self, point):
        print("You Get {} Point".format(point))

    # 游戏流程
    def Play(self):
        # 初始化游戏
        if self.Initial() == False:
            print("Initial Game Fail!")
            return False
        # 开始游戏
        point = self.PlayGame()
        # 结束游戏
        self.EndGame()
        # 显示分数
        self.ShowPoint(point)
        return True

        