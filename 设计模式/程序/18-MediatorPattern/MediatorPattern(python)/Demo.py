# python 实现中介者模式

# 聊天房类
class ChatRoom:
    def ShowMessage(user, message):
        print('[{0}] say: {1}'.format(user.GetName(), message))

# 用户类
class User:
    def __init__(self, name):
        self.__name = name
    
    def SendMessage(self, message):
        ChatRoom.ShowMessage(self, message)

    def GetName(self):
        return self.__name


user1 = User('YeChen')
user2 = User('XuYuting')
user1.SendMessage('Are you free?')
user2.SendMessage('Yes, go to play!')