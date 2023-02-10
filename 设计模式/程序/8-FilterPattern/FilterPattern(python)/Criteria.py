from Person import Person
import abc

# 基类
class Criteria(metaclass = abc.ABCMeta):
    @abc.abstractmethod
    def MeetCriteria(self, persons):
        pass

# 实现
class CriteriaMale(Criteria):
    def MeetCriteria(self, persons):
        malePerons = []
        for person in persons:
            if person.GetGender() == "Male":
                malePerons.append(person)
        return malePerons

class CriteriaFemale(Criteria):
    def MeetCriteria(self, persons):
        femalePersons = []
        for person in persons:
            if person.GetGender() == "Female":
                femalePersons.append(person)
        return femalePersons

class CriteriaSingle(Criteria):
    def __init__(self):
        pass
    def MeetCriteria(self, persons):
        singlePersons = []
        for person in persons:
            if person.GetMaritalStatus() == "Single":
                singlePersons.append(person)
        return singlePersons

# 与条件过滤
class AndCriteria(Criteria):
    def __init__(self, criteria1, criteria2):
        self.criteria1 = criteria1
        self.criteria2 = criteria2
    def MeetCriteria(self, persons):
        persons1 = self.criteria1.MeetCriteria(persons)
        persons2 = self.criteria2.MeetCriteria(persons1)
        return persons2

# 或条件过率
class OrCriteria(Criteria):
    def __init__(self, criteria1, criteria2):
        self.criteria1 = criteria1
        self.criteria2 = criteria2
    def MeetCriteria(self, persons):
        persons1 = self.criteria1.MeetCriteria(persons)
        persons2 = self.criteria2.MeetCriteria(persons)
        for person in persons1:
            if person not in persons2:
                persons2.append(person)
        return persons2