#include "Person.h"
#include "Criteria.h"
using namespace FilterPattern;
#include <iostream>
#include <string>
#include <list>


int main()
{
    // 构造四个人
    std::list<Person*> persons;
    persons.push_back(new Person("YeChen", MALE, SWEETHEART));
    persons.push_back(new Person("XuYuting", FEMALE, SWEETHEART));
    persons.push_back(new Person("MiaoJie", MALE, SINGLE)); 
    persons.push_back(new Person("YangYuhua", FEMALE, MARRIED));
    persons.push_back(new Person("ZhangChao", MALE, SINGLE));
    persons.push_back(new Person("YeXianshuo", MALE, MARRIED));

    // 过滤男性
    Filter filter1(new IsMale());
    std::list<Person*> malePerons = filter1(persons);
    std::cout << "Show Male:" << std::endl;
    for (auto iter = malePerons.begin(); iter != malePerons.end(); ++iter)
        std::cout << *(*iter);

    // 过滤女性
    Filter filter2(new IsFemale());
    std::list<Person*> femalePerons = filter2(persons);
    std::cout << "Show Female:" << std::endl;
    for (auto iter = femalePerons.begin(); iter != femalePerons.end(); ++iter)
        std::cout << *(*iter);

    // 过滤出男性并且单身
    Filter filter_of_male_and_single(new Criterias({new IsMale(), new IsSingle()}, And));
    std::list<Person*> persons1 = filter_of_male_and_single(persons);
    std::cout << "Show Male and Single" << std::endl;
    for (auto iter = persons1.begin(); iter != persons1.end(); iter++)
        std::cout << *(*iter);

    // 过滤出女性或者结婚
    Filter filter_of_female_or_married(new Criterias({new IsFemale(), new IsMarried()}, Or));
    std::list<Person*> persons2 = filter_of_female_or_married(persons);
    std::cout << "Show Female or married" << std::endl;
    for (auto iter = persons2.begin(); iter != persons2.end(); iter++)
        std::cout << *(*iter);

    // 释放资源
    for (auto iter = persons.begin(); iter != persons.end(); iter++)
    {
        if (*iter != nullptr)
            delete *iter;
    }

    return 0;
};