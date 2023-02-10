#include <iostream>
#include <memory>
#include <list>


#define COPY_OPERATION
#define MOVE_OPERATION

class Object
{
public:
    Object(int data): _data(data) { std::cout << "common construction\n"; }

#ifdef COPY_OPERATION
    Object(const Object& that): _data(that._data) { std::cout << "copy construction\n"; }
    Object& operator = (const Object& that) 
    {
        if (&that == this) return *this;
        this->_data = that._data;
        std::cout << "copy assignment\n";
        return *this;
    }
#endif

#ifdef MOVE_OPERATION
    Object(Object&& that): _data(that._data) { std::cout << "move construction\n"; }
    Object& operator = (Object&& that) 
    {
        this->_data = that._data;
        std::cout << "move assignment\n";
        return *this;
    }
#endif

    ~Object() { std::cout << "destruction\n"; }
private:
    int _data;
};

namespace no_universal_references
{
    std::list<Object> objects;

    void LogObject(const Object& obj)
    {
        std::cout << "Log\n";
        objects.push_back(obj);
    }

    void test()
    {
        Object obj(123);
        LogObject(obj);
        LogObject(Object(67));
        LogObject(1);
    }
}

namespace universal_references
{
    std::list<Object> objects;

    template<typename T>
    void LogObject(T&& obj)
    {
        std::cout << "Log\n";
        objects.push_back(std::forward<T>(obj));
    }

    void test()
    {
        Object obj(123);
        LogObject(obj);
        LogObject(Object(67));
        // 直接把 1 给 push_back 创建对象
        LogObject(1);
    }
}

namespace universal_references_constrction
{
    std::string names[] = {
        "YeChen", "XuYuting", "XiaoMing", "XiaoHong"
    };

    class Person
    {
    public:
        template <typename T>
        Person(T&& name) : _name(std::forward<T>(name)) {} 

        Person(std::size_t index) : _name(names[index]) {}

    private:
        std::string _name;
    };

    void test()
    {
        Person p1("hhh");
        // Person p2(1); --> 匹配到通用引用，报错
        // Person p3(p1); --> 匹配到通用引用，报错
        const Person p4("adads");
        Person p5(p4);  // 不报错~
    } 
}


int main()
{
    universal_references::test();
    return 0;
}