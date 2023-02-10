class Person(object):
    def __init__(self, name, gender, maritalStatus):
        self.name = name
        self.gender = gender
        self.maritalStatus = maritalStatus
    def GetName(self):
        return self.name
    def GetGender(self):
        return self.gender
    def GetMaritalStatus(self):
        return self.maritalStatus


def PrintPersons(persons):
    for person in persons:
        print("[Name: {}, Gender: {}, MaritalStatus: {}]".format(person.GetName(), person.GetGender(), person.GetMaritalStatus()))
