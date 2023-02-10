#ifndef __PERSON_H__
#define __PERSON_H__
#include <string>
#include <iostream>


namespace FilterPattern
{
    /* 性别枚举 */
    enum Gender { MALE = 0, FEMALE };
    /* 婚恋状态枚举 */
    enum MaritalStatus { SINGLE = 0, MARRIED, SWEETHEART }; 

    /* 人类 */
    class Person
    {
    public:
        /* 构造函数 */
        Person(std::string name, Gender gender, MaritalStatus maritalStatus);
        /* getter */
        const std::string& GetName() const;
        Gender GetGender() const;
        MaritalStatus GetMaritalStatus() const;

    private:
        /* 一些基本数据 */
        std::string _name;
        Gender _gender;
        MaritalStatus _maritalStatus;
    };

    /* 运算符重载 */
    std::ostream& operator << (std::ostream& out, const Person& person);
}



#endif