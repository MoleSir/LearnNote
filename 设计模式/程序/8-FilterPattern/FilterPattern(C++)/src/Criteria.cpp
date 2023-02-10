#include "Criteria.h"
#include "Person.h"


namespace FilterPattern
{
    /* 各个单独判断仿函数的实现 */
    bool IsMale::operator () (const Person& person)
    {
        return person.GetGender() == MALE;
    }

    bool IsFemale::operator () (const Person& person) 
    {
        return person.GetGender() == FEMALE;
    }

    bool IsSingle::operator () (const Person& person) 
    {
        return person.GetMaritalStatus() == SINGLE;
    }

    bool IsMarried::operator () (const Person& person) 
    {
        return person.GetMaritalStatus() == MARRIED;
    }

    /* 多标准的构造函数 */
    Criterias::Criterias(const std::list<Criteria*>& criteriaArray, bool Or_And):
        _criterias(criteriaArray), _Or_And(Or_And)
    {
    }

    /* 多标准仿函数的实现 */ 
    bool Criterias::operator () (const Person& person) 
    {
        for (auto iter = _criterias.begin(); iter != _criterias.end(); ++iter)
        {
            // 如果要求是 And，也就是 0，只要一个是0，那么整个函数返回0，Or就相反
            if ( (*(*iter))(person) == _Or_And )
                return _Or_And;
        }
        return !_Or_And;
    }

    Criterias::~Criterias()
    {
        // 把链表里的指针释放
        for (auto iter = this->_criterias.begin(); iter != this->_criterias.end(); ++iter)  
        {
            if (*iter != nullptr)
            {
                delete *iter;
                *iter = nullptr;
            }
        }
    }

    Filter::Filter(Criteria* criteria): _criteria(criteria)
    {}

    Filter::~Filter()
    {
        if (this->_criteria != nullptr) 
        {
            delete this->_criteria;
            this->_criteria = nullptr;
        }
    }

    /* Filter 函数 */
    std::list<Person*> Filter::operator() (const std::list<Person*>& persons) const
    {
        std::list<Person*> filteredPerons;
        // 依次取出链表中的每个人进行判断
        for (auto iter = persons.begin(); iter != persons.end(); iter++)
        {
            if (    (*(this->_criteria)) ((*(*iter))) == true    )
                filteredPerons.push_back(*iter);
        }
        return filteredPerons;
    }
}