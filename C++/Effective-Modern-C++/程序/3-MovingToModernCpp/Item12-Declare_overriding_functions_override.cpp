#include <iostream>
#include <string>


namespace no_override
{
    class Base
    {
    public:
        Base() {}
        virtual void f1(int a) {}
        virtual std::string f3(double d) const { return std::string("hello world!"); }
        virtual void f4() & {} 
    };

    class Derived : public Base
    {
    public:
        Derived() : Base() {}
        virtual void f1(float a) {}
        virtual std::string f3(double d) { return std::string("hello world!"); }
        virtual void f4() && {} 
    };
}

#define _OVERRIDE_SWITCH_ 1
namespace override
{
#ifndef _OVERRIDE_SWITCH_
    class Base
    {
    public:
        Base() {}
        virtual void f1(int a) {}
        virtual std::string f3(double d) const { return std::string("hello world!"); }
        virtual void f4() & {} 
    };

    class Derived : public Base
    {
    public:
        Derived() : Base() {}
        virtual void f1(float a) override  {}
        virtual std::string f3(double d) override { return std::string("hello world!"); }
        virtual void f4() && override {} 
    };
#endif
}

namespace reference_qualifiers
{
    class Data
    {
    public:
        Data() { std::cout << "common construction\n"; }
        Data(const Data&) { std::cout << "copy construction\n"; }
        Data& operator = (const Data&) { std::cout << "copy assignment\n"; return *this; }
        Data(Data&&) { std::cout << "move construction\n"; }
        Data& operator = (Data&&) { std::cout << "move assignment\n"; return *this; }
    };

    class Widget
    {
    public:
        Widget() : _data() {}
        // 左值限定
        Data& GetData() & 
        {   
            // 返回的是 _data 本身，并且返回类型是 Data&，就是返回了 this-_data 的左值引用 
            return this->_data; 
        }
        // 右值限定
        Data GetData() && 
        {
            // 返回的是 _data 的右值引用，并且返回类型是 Data，就是返回了  _data 的右值引用 本身
            return std::move(this->_data); 
        }

    private:
        Data _data;
    };

    Widget GetWidget()
    {
        Widget w;
        return w;
    }

    void test()
    {
        Widget w;
        Data d1 = w.GetData();
        Data d2 = GetWidget().GetData();
    }
}


int main()
{
    no_override::Derived d; // 不报错
    // override::Derived d;  // 报错

    reference_qualifiers::test();

    return 0;
}