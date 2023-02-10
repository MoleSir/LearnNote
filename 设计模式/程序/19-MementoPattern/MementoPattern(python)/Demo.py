from Originator import Originator 
from Memento import Memento
from CareTaker import CareTaker

originator = Originator()
careTaker = CareTaker()

originator.SetState('State #1')
originator.SetState('State #2')

# 保存状态
careTaker.Add(originator.SaveStateToMemento())

# 改变状态
originator.SetState('State #3')

# 再保存
careTaker.Add(originator.SaveStateToMemento());

# 再改变状态
originator.SetState('State #4')

# 输出当前状态
print('Current State: {0}'.format(originator.GetState()))

# 恢复第0个保存状态
originator.GetStateFromMemento(careTaker.Get(0))
print('First Svaed State: {0}'.format(originator.GetState()))

# 恢复第1个保存状态
originator.GetStateFromMemento(careTaker.Get(1))
print('Second Svaed State: {0}'.format(originator.GetState()))
