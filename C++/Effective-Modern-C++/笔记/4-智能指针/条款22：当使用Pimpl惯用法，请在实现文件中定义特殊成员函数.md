## 条款 22：当使用Pimpl惯用法，请在实现文件中定义特殊成员函数

​		Item 22: When using the Pimpl Idiom, define special member functions in the implementation file

## Pimpl 惯用法

当一个类的内需要包含其他的类，就需要引入头文件 `#include <...>` ；

那么如果其依赖头文件发生变化，就导致此类需要重新编译，所有包含使用这个类的文件都会被重新编译；

使用 Pimpl 后可以解决这个问题：

````c++
class Widget                        //仍然在“widget.h”中
{
public:
    Widget();
    ~Widget();                      //析构函数在后面会分析
    …
private:
    struct Impl;                    //声明一个 实现结构体
    Impl *pImpl;                    //以及指向它的指针
};
````

在类中声明（不在头文件中定义）一个结构体 `Impl`，再声明一个成员指针 `Impl *pImpl`；

虽然编译器此时不知道 `Impl` 结构体内容的成员，无法计算结构大小，但至少知道一个指针的大小，所以这样的类定义的可以编译的；

之后在 `Widget.cpp` 中定义这个结构体：

````c++
#include "widget.h"             //以下代码均在实现文件“widget.cpp”里
#include "gadget.h"
#include <string>
#include <vector>

struct Widget::Impl {           
    std::string name;           //Widget::Impl类型的定义
    std::vector<double> data;
    Gadget g1,g2,g3;
};

Widget::Widget()                //为此Widget对象分配数据成员
: pImpl(new Impl) {}

Widget::~Widget()               //销毁数据成员
{ delete pImpl; }
````

现在只有 `.pp` 文件与这些类内成员产生依赖关系；

如果这个成员发生变化，只要 `Widget.cpp` 需要重新编译。而 `Widget.h` 完全不需要变化，包括那么包含 `Widget.h` 的使用者。减少了文件之间的编译依赖；



## 使用智能指针改造

### 改造方案

C++98 的 Pimpl 惯用法使用原始指针，在构造函数中创建，析构中删除；在 C++11 更好的做法是使用智能指针；

头文件改造为：

````c++
class Widget {                      //在“widget.h”中
public:
    Widget();
    …
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;    //使用智能指针而不是原始指针
};
````

实现文件改为：

````c++
#include "widget.h"                 //在“widget.cpp”中
#include "gadget.h"
#include <string>
#include <vector>

struct Widget::Impl {               //跟之前一样
    std::string name;
    std::vector<double> data;
    Gadget g1,g2,g3;
};

Widget::Widget()                   
: pImpl(std::make_unique<Impl>())   //来创建std::unique_ptr
{}
````

这里没有声明析构，`std::unique_ptr` 自身析构时会释放资源；

### 代码的问题

以上代码通过编译，但不可以使用：

````c++
#include "Wiget.h"
Widget w;				// 报错
````

报错的原因是：

由于没有编写析构，编译器会先成默认的析构，在定义 `Impl` 之前，即在析构函数中，`Impl` 还没有定义，是一个未完成类型；

而析构函数会调用 `std::unique_ptr` 的默认析构，使用 `delete` 释放内存，而 `delete` 对未完成类型对象时报错；

### 解决方式

理解报错问题后，解决方式很简单，只要在析构之前定义 `Impl` 即可，所以需要手动声明析构，并且在实现文件中定义在 `Impl` 之后：

````c++
class Widget {                  //跟之前一样，在“widget.h”中
public:
    Widget();
    ~Widget();                  //只有声明语句
    …
private:                        
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
````

实现文件中，一定要先定义 `Impl`：

````c++
#include "widget.h"
#include "gadget.h"
#include <string>
#include <vector>

struct Widget::Impl {               //跟之前一样，定义Widget::Impl
    std::string name;
    std::vector<double> data;
    Gadget g1,g2,g3;
}

Widget::Widget()                    //跟之前一样
: pImpl(std::make_unique<Impl>())
{}

Widget::~Widget() = default;
````

### 增加移动操作

手动声明了析构函数之后，编译器不会帮助用户生成移动操作，所以需要手动声明：

````c++
class Widget {                                  //仍然在“widget.h”中
public:
    Widget();
    ~Widget();
    Widget(Widget&& rhs) = default;             //思路正确，
    Widget& operator=(Widget&& rhs) = default;  //但代码错误
    …
private:                                        //跟之前一样
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
````

但这样是错的，原因与析构函数报错相同，应该把移动操作的定义放在 `Impl` 之后，所以应该只在头文件中声明，cpp 中实现（并且在 `Impl`之后）：

````c++
class Widget {                          //仍然在“widget.h”中
public:
    Widget();
    ~Widget();

    Widget(Widget&& rhs);               //只有声明
    Widget& operator=(Widget&& rhs);
    …

private:                                //跟之前一样
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
````

````c++
#include <string>                   //跟之前一样，仍然在“widget.cpp”中
…
    
struct Widget::Impl { … };          //跟之前一样

Widget::Widget()                    //跟之前一样
: pImpl(std::make_unique<Impl>())
{}

Widget::~Widget() = default;        //跟之前一样

Widget::Widget(Widget&& rhs) = default;             //这里定义
Widget& Widget::operator=(Widget&& rhs) = default;
````

### 增加复制操作

增加复制操作的方法也是一样的，但要注意复制是生成一份新的，需要使用深拷贝：

````c++
class Widget {                          //仍然在“widget.h”中
public:
    …

    Widget(const Widget& rhs);          //只有声明
    Widget& operator=(const Widget& rhs);

private:                                //跟之前一样
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
````

````c++
#include <string>                   //跟之前一样，仍然在“widget.cpp”中
…
    
struct Widget::Impl { … };          //跟之前一样

Widget::~Widget() = default;		//其他函数，跟之前一样

Widget::Widget(const Widget& rhs)   //拷贝构造函数
: pImpl(std::make_unique<Impl>(*rhs.pImpl))
{}

Widget& Widget::operator=(const Widget& rhs)    //拷贝operator=
{
    *pImpl = *rhs.pImpl;
    return *this;
}
````

上面调用的函数都是 `Impl` 结构体的拷贝，而不是 `unique_ptr` 的；

````c++
pImpl(std::make_unique<Impl>(*rhs.pImpl))
````

在 `make_unique` 中写入的参数会用于 `Impl` 的构造，这里用的是 `rhs` 的 `Impl` 对象，所以调用的是 `Impl` 的拷贝构造，默认的操作就是将其中的成员一个个复制；

````c++
*pImpl = *rhs.pImpl;
````

这个就是各取自身的 `Impl` 对象与 `rhs` 的 `Impl` 对象，进行拷贝；



## 使用 `shared_ptr` 

如果使用的是 `shared_ptr` ，不需要那么麻烦，因为其删除器不是智能指针的一部分；



## 请记住

- Pimpl惯用法通过减少在类实现和类使用者之间的编译依赖来减少编译时间。
- 对于`std::unique_ptr`类型的`pImpl`指针，需要在头文件的类里声明特殊的成员函数，但是在实现文件里面来实现他们。即使是编译器自动生成的代码可以工作，也要这么做。
- 以上的建议只适用于`std::unique_ptr`，不适用于`std::shared_ptr`。



