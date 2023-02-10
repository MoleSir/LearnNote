## 条款 5：优先考虑`auto`而非显式类型声明

​	Item 5: Prefer `auto` to explicit type declarations

使用 `auto` 有很多好处：

使用 `auto` 可以防止编程时忘记给变量初始化；

````c++
auto x = 0; // 不初始化报错
````

使用 `auto` 可以避免必须编写很长的迭代器返回值类型；

````c++
template <typename It>
void dwin(It b, It e)
{
    while (b != e)
    {
        auto currValue = *b;
	}
}
````

使用 `auto` 可以定义一些只有编译器知道的数据类型；

````c++
auto derefUPLess = 
    [](const std::unique_ptr<Widget> &p1,       //用于std::unique_ptr
       const std::unique_ptr<Widget> &p2)       //指向的Widget类型的
    { return *p1 < *p2; };                      //比较函数
````

在 C++ 14 中，可以在 lambda 表达式中使用 `auto`：

````c++
auto derefLess =                                //C++14版本
    [](const auto& p1,                          //被任何像指针一样的东西
       const auto& p2)                          //指向的值的比较函数
    { return *p1 < *p2; };
````

虽然 `std::function` 也可以定义 lambda 对象，但是编写过程复杂，并且需要分配内存，消耗更多内存；

使用 `auto` 可以忽略底层的机械细节：

````c++
std::vector<int> v;
unsigned sz = v.size();
````

使用 `unsigned` 变量保存 `size()`，但是 `v.size()`的标准返回类型是`std::vector<int>::size_type`；

在**Windows 32-bit**上`std::vector<int>::size_type`和`unsigned`是一样的大小，但是在**Windows 64-bit**上`std::vector<int>::size_type`是64位，`unsigned`是32位。这意味着这段代码在Windows 32-bit上正常工作，但是当把应用程序移植到Windows 64-bit上时就可能会出现一些问题；

但 `auto` 可能使得代码不易阅读，`auto` 推导错误等问题；



## 请记住

- `auto` 变量必须初始化，通常它可以避免一些移植性和效率性的问题，也使得重构更方便，还能让你少打几个字。
- 正如Item2 和 6 讨论的，`auto` 类型的变量可能会踩到一些陷阱；