#include <iostream>
#include <string>
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


namespace give_up_overload
{
    std::list<Object> objects;
    Object objectArr[] = {
        Object(565), Object(54), Object(12)
    }; 

    template <typename T>
    void LogAndAddObject(T&& obj)
    {
        std::cout << "Log\n";
        objects.push_back(std::forward<T>(obj));
    }

    void LogAndAddObjectIdx(int index)
    {
        std::cout << "Log\n";
        objects.push_back(objectArr[index]);
    }
}


namespace tag_dispatch
{
    std::list<Object> objects;
    Object objectArr[] = {
        Object(565), Object(54), Object(12)
    }; 

    template <typename T>
    void LogAndAddImp(T&& obj, std::false_type)
    {
        objects.push_back(std::forward<T>(obj));
    }

    void LogAndAddImp(int index, std::true_type)    
    {
        objects.push_back(objectArr[index]);
    }
    
    // just interface
    template <typename T>
    void LogAndAdd(T&& obj)
    {
        std::cout << "Log\n";
        LogAndAddImp(
            std::forward<T>(obj), 
            std::is_integral<typename std::remove_reference<T>::type>()
        );
    }

    void test()
    {
        std::cout << "\n================= test tag dispatch ==================\n";
        LogAndAdd(Object(122));
        LogAndAdd(123);
    }
}

namespace SFINAE
{
    std::string names[] = {
        "YeChen", "XuYuting", "XiaoMing"
    };

    class Person
    {
    public:
        template <
            typename T,
            typename = typename std::enable_if <
                !std::is_same< Person, typename std::decay<T>::type >::value
            >::type
        >
        explicit Person(T&& name) : _name(std::forward<T>(name)) 
        { std::cout << "template construction\n"; }

    private:
        std::string _name;
    };

    void test()
    {
        std::cout << "\n================= test SFINAE ==================\n";
        Person p1(std::string("hhh"));
        Person p2(p1);
    }
}   


int main()
{
    SFINAE::test();
}