#ifndef __CRITERIA_H__
#define __CRITERIA_H__
#include <list>
#include "Person.h"


namespace FilterPattern
{
    const bool And = false;
    const bool Or = true;

    /* 标准的基类，提供一个接口：重载()运算符，可以算是一个仿函数吧 */
    class Criteria
    {
    public:
        virtual bool operator () (const Person& person) = 0;
    };

    /* 判断是否男人的仿函数 */
    class IsMale: public Criteria
    {
    public:
        virtual bool operator () (const Person& person) override;
    };

    /* 判断是否女人的仿函数 */
    class IsFemale: public Criteria
    {
    public:
        virtual bool operator () (const Person& person) override;
    };

    /* 判断是否单身的仿函数 */
    class IsSingle: public Criteria
    {
    public:
        virtual bool operator () (const Person& person) override;
    };

    /* 判断是否结婚的仿函数 */
    class IsMarried: public Criteria
    {
    public:
        virtual bool operator () (const Person& person) override;
    };

    /* 只需要继续拓展判断单个的仿函数 */


    /* 多重判断 *************************************************************/
    class Criterias: public Criteria
    {
    public:
        // 构造函数
        Criterias(const std::list<Criteria*>& criteriaArray, bool Or_And);
        // 析构函数释放资源
        ~Criterias();
        // 运算符重载
        virtual bool operator () (const Person& person) override;
    private:
        // 将单个判断的仿函数放入这个链表
        std::list<Criteria*> _criterias;
        // 确定这些关系是或还是且
        bool _Or_And;
    };


    /* Filter 类 **************************************************************/
    class Filter
    {
    public:
        // 构造函数
        Filter(Criteria* criteria);
        // 析构函数，释放资源
        ~Filter();
        // 返回 persons 中满足某个条件的 Person，返回一个新链表
        std::list<Person*> operator() (const std::list<Person*>& persons) const;

    private:
        /* 标准 */
        Criteria* _criteria;
    };
}


#endif