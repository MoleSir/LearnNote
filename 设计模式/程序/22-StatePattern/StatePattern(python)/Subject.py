class Subject:
    def __init__(self, state):
        self.state = state

    def SetState(self, state):
        self.state = state

    def Operation1(self, message):
        self.state.DoOperation1(message)

    def Operation2(self, message):
        self.state.DoOperation2(message)

    def Operation3(self, message):
        self.state.DoOperation3(message)