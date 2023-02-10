from State import *
from Subject import *

a = StateA()
b = StateB()
c = StateC()

subject = Subject(a)
subject.Operation1('qqqqq')

subject.SetState(b)
subject.Operation2('ddddd')

subject.SetState(c)
subject.Operation3('ooooo')
