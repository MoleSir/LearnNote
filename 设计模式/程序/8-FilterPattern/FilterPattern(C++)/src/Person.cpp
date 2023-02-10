#include "Person.h"
#include <iostream>
#include <string>


namespace FilterPattern
{
    std::string genderStrs[2] = {std::string("Male"), std::string("Female")};
    std::string maritalStatusStrs[3] = {std::string("Single"), 
                                        std::string("Married"), 
                                        std::string("Sweetheart")};


    Person::Person(std::string name, Gender gender, MaritalStatus maritalStatus):
    _name(name), _gender(gender), _maritalStatus(maritalStatus)
    {}

    const std::string& Person::GetName() const
    {
        return this->_name;
    }

    Gender Person::GetGender() const
    {
        return this->_gender;
    }

    MaritalStatus Person::GetMaritalStatus() const
    {
        return this->_maritalStatus;
    }

    std::ostream& operator << (std::ostream& out, const Person& person)
    {
        out << "[Name: " << person.GetName() << ", Gender: " << genderStrs[person.GetGender()] 
            << ", MaritaStatus: " << maritalStatusStrs[person.GetMaritalStatus()] << "]\n";
        return out;
    }
}