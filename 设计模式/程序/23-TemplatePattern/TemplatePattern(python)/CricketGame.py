from Game import Game 

class CricketGame(Game):
    # 实现三个函数
    def Initial(self):
        print('Prepare Cricket Ground...')
        print('Wait Players...')
        print('Wait Ball...')
        return True

    def PlayGame(self):
        print('Playing...')
        print('hithithit')
        return 12

    def EndGame(self):
        print('Player Take Shower...')
        print('Clean Cricket ground...')
        print('Customer leaves...')