## 条款 11：优先考虑使用*deleted*函数而非使用未定义的私有声明

​		Item 11: Prefer deleted functions to private undefined ones.

## 删除成员函数

标准库 iostream 的顶部是模板类 `basic_ios`，通常禁止其拷贝；

在 C++ 98 中，将其拷贝构造与拷贝赋值声明 `private`：

````c++
template <class charT, class traits = char_traits<charT> >
class basic_ios : public ios_base {
public:
    ...
private:
    basic_ios(const basic_ios&);
    basic_ios& operator = (const basic_ios&);
};
````

在C++11中有一种更好的方式达到相同目的：用 “`= delete`” 将拷贝构造函数和拷贝赋值运算符标记为 *deleted* 函数：

````c++
template <class charT, class traits = char_traits<charT> >
class basic_ios : public ios_base {
public:
    ...
    basic_ios(const basic_ios&) = delete;
    basic_ios& operator = (const basic_ios&) = delete;
};
````

*deleted* 函数不能以任何方式被调用，即使在成员函数或者友元函数里面调用*deleted* 函数也不能通过编译。这是较之C++98行为的一个改进；

通常，被删除的函数应该声明为 `public`，否则编译器的报错信息可能就是调用了私有函数，而不是调用了被删除的颜色；



## 删除非成员函数

不仅对成员函数可以删除，`delete` 运行删除任何函数；

考虑这样的非成员函数，参数接受一个 `int`，

````c++
bool isLucky(int number);
````

由于 C++ 沉重的 C 包袱，字符类型，布尔类型，甚至浮点都可以隐式转换为 `int`，那么这些调用也是允许：

````c++
if (isLucky('a')) …         //字符'a'是幸运数？
if (isLucky(true)) …        //"true"是?
if (isLucky(3.5)) …         //难道判断它的幸运之前还要先截尾成3？
````

如果幸运数必须真的是整型，应该禁止这些调用通过编译；

其中一种方法就是创建*deleted*重载函数，其参数就是想要过滤的类型：

````c++
bool isLucky(int number);       //原始版本
bool isLucky(char) = delete;    //拒绝char
bool isLucky(bool) = delete;    //拒绝bool
bool isLucky(double) = delete;  //拒绝float和double
````



## 删除特化模板

甚至不止函数，`delete` 可以删除特化的模板：

````c++
template<typename T>
void processPointer(T* ptr);

template<>
void processPointer<void>(void*) = delete;

template<>
void processPointer<char>(char*) = delete;
````

使用`void*`和`char*`调用`processPointer`就是无效的；

模板函数有一个特性，特化的版本必须与主函数模板在同一个命名空间；甚至在同一个类中的不同访问级别都不属于同一作用域；

所以不无使用 `private` 的方式删除类中某个模板函数的特化：

````c++
class Widget {
public:
    …
    template<typename T>
    void processPointer(T* ptr)
    { … }
private:
    template<>                          //错误！
    void processPointer<void>(void*);
};
````

而 *deleted* 函数不需要一个不同的访问级别，且他们可以在类外被删除（因此位于命名空间作用域）：

````c++
class Widget {
public:
    …
    template<typename T>
    void processPointer(T* ptr)
    { … }
};

template<>                                          //还是public，
void Widget::processPointer<void>(void*) = delete;  //但是已经被删除了
````



## 请记住

- 比起声明函数为`private`但不定义，使用*deleted*函数更好
- 任何函数都能被删除（be deleted），包括非成员函数和模板实例（译注：实例化的函数）