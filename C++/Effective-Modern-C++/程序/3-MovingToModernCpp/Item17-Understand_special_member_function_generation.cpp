#include <iostream>


// Widget1 : 只定义构造
class Widget1
{
public:
    Widget1() {}
};

// Widget2 : 给出析构
class Widget2
{
public:
    Widget2() {}
    ~Widget2() {}
};

// Widget3 : 给出了构造
class Widget3
{
public:
    Widget3() {}
    Widget3(const Widget3&) {}
};

// Widget4 ： 给出了移动
class Widget4
{
public:
    Widget4() {}
    Widget4(Widget4&&) {}
};

class Widget5
{
public:
    Widget5() {}

    template <typename T>
    Widget5(const T& rhs) { std::cout << "Tempalte copy\n"; }
   
    template <typename T>
    Widget5& operator = (const T& rhs) { std::cout << "Template assignment\n"; return *this; }
};

int main()
{
    // 编译成功 ！
    Widget1 w11;
    Widget1 w12{w11};
    Widget1 w13{std::move(w11)};
    w12 = w11;
    w13 = std::move(w11);

    // 编译成功 ！ 有点奇怪，按理说有了析构就不能有默认拷贝与移动了
    Widget2 w21;
    Widget2 w22{w21};
    Widget2 w23{std::move(w21)};
    w22 = w21;
    w23 = std::move(w21);

    // 编译成功 ！ ??????????
    Widget3 w31;
    Widget3 w32(w31);
    Widget3 w33(std::move(w31));
    w32 = w31;
    w33 = std::move(w31);

    // 编译失败，因为有了移动就不能生成默认拷贝
    Widget4 w41;
    // Widget4 w42(w41);
    Widget4 w43(std::move(w41));
    // w42 = w41;
    w43 = std::move(w41);

    Widget5 w51;
    // 调用的不是函数模板，而是编译器产生的默认拷贝
    Widget5 w52(w51);
}