#include <iostream>
#include <string>

namespace Item7_test
{
    class Widget
    {
    public:
        Widget() 
            : _b(true), _i(1), _f(2.5), _s("defualt construction\n")
        {
            std::cout << this->_s;
        }
        Widget(bool b, int i, float f, const std::string& s)
            : _b(b), _i(i), _f(f), _s(s) 
        {
            std::cout << "common construction\n";
        }
        Widget(std::initializer_list<double> initList) 
            : _b(false), _i(0), _f(250.0), _s("initialzer_list construction\n")
        {
            std::cout << this->_s;
            auto iter = initList.begin();
            this->_f = *iter; 
        }
        Widget(bool b, int i, float f)
            : _b(b), _i(i), _f(f), _s("initialzer_list like construction\n")
        {
            std::cout << this->_s;
        }

    private:
        bool _b;
        int _i;
        float _f;
        std::string _s;
    };


    template <typename ObjType, typename... Ts>
    ObjType* GetObj1(Ts&&... params)
    {
        return new ObjType(std::forward<Ts>(params)...);
    }

    template <typename ObjType, typename... Ts>
    ObjType* GetObj2(Ts&&... params)
    {
        return new ObjType{std::forward<Ts>(params)...};
    }


    void test1()
    {
        Widget w1;          // defualt construction
        Widget w2();        // defualt construction 
        Widget w3{};        // common construction ?
        Widget w4(true, 12, 2229.3, "w4"); // common construction
        Widget w5{false, 1233, 2202.222, "w5"}; // common construction
        Widget w6(true, 12, 23333.3);   // initialzer_list like construction
        Widget w7{false, 555, 34.5};    // initialzer_list construction
        Widget w8({});      // initialzer_list construction
        Widget w9({});      // initialzer_list construction
    }

    void test2()
    {
        //Widget* pw1 = GetObj1<Widget>(false, 555, 34.5);
        //Widget* pw2 = GetObj2<Widget>(false, 555, 34.5);
    }
}

namespace question
{
    class Object
    {
    public:
        Object(int data): _data(data) { std::cout << "common construction\n"; }
        Object(const Object& that): _data(that._data) { std::cout << "copy construction\n"; }
        Object(Object&& that): _data(that._data) { std::cout << "move construction\n"; }
        Object& operator = (const Object& that) 
        {
            this->_data = that._data;
            std::cout << "copy assignment\n";
            return *this;
        }
        Object& operator = (Object&& that) 
        {
            this->_data = that._data;
            std::cout << "move assignment\n";
            return *this;
        }
    private:
        int _data;
    };

    // 万能引用
    void test1(const Object& obj)
    {
        Object obj1(obj);
        Object obj2(std::move(obj));
    }
    // 左值
    void test2(Object& obj)
    {
        Object obj1(obj);
        Object obj2(std::move(obj));
    }
    // 右值
    void test3(Object&& obj)
    {
        Object obj1(obj);
        Object obj2(std::move(obj));
    }
}

int main()
{   
    using namespace Item7_test;
    // tets1();
    // test2();

    using namespace question;
    Object obj(12);
    test1(obj);
    //test1(std::move(obj));

    return 0;
}