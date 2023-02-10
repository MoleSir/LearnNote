from Person import *
from Criteria import *

persons = []

persons.append(Person("Robert","Male", "Single"))
persons.append(Person("John","Male", "Married"))
persons.append(Person("Laura","Female", "Married"))
persons.append(Person("Diana","Female", "Single"))
persons.append(Person("Mike","Male", "Single"))
persons.append(Person("Bobby","Male", "Single"))

male = CriteriaMale()
female = CriteriaFemale()
single = CriteriaSingle()
singleMale = AndCriteria(single, male)
singleOrFemale = OrCriteria(single, female)

print("Males: ")
PrintPersons(male.MeetCriteria(persons))

print("\nFemales: ")
PrintPersons(female.MeetCriteria(persons))

print("\nSingle Males: ")
PrintPersons(singleMale.MeetCriteria(persons))

print("\nSingle Or Females: ")
PrintPersons(singleOrFemale.MeetCriteria(persons))