from Observer import *
from Subject import *

subject = Subject(0)

b = BinaryObserver()
o = OctalObserver()
h = HexaObserver()

subject.AddObserver(b)
subject.AddObserver(o)
subject.AddObserver(h)

print("First state change: 15")
subject.SetState(15)
print("Second state change: 10")
subject.SetState(10)