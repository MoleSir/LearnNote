from Game import Game 

class FootballGame(Game):
    # 实现三个函数
    def Initial(self):
        print('Prepare Football Ground...')
        print('Wait Players...')
        return True

    def PlayGame(self):
        print('Playing...')
        print('tititititi')
        return 3

    def EndGame(self):
        print('Player Take Shower...')
        print('Clean Football ground...')