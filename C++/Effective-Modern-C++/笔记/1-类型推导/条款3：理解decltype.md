# 条款 3：理解 `decltype` 

​		Item 3: Understand decltype

`decltype` 可以根据一个名字或者表达式得到其类型；

在C++11中，`decltype` 最主要的用途就是用于声明函数模板，而这个函数返回类型依赖于形参类型；

````c++
template <typename Container, typename Index>
auto Access(Container& c, Index i) -> decltype(c[i])
{
    return c[i];
}
````

其中 `auto` 不会做任何的类型推导工作，只是暗示使用了 C++11 的**尾置返回类型**语法，即在函数形参列表后面使用一个 ”`->`“ 符号指出函数的返回类型；

在 C++ 14 中，`auto` 功能更加强大，可以自己推导出返回类型：

````c++
template <typename Container, typename Index>
auto Access(Container& c, Index i)
{
    return c[i];
}
````

其实就是完成  `auto res = c[i] ` 的推导；

但根据条款 1、2，`c[i]` 通常返回的是一个引用，即可以使用这个 `c[i]` 修改容器内部的值；

那么根据推导法则， `auto` 为第三类值传递推导，得到的只是一个由 `c[i]` 拷贝过来的临时对象；

那么就不能使用这个返回值改变原来容器的值：

````c++
std::deque<int> d;
authAndAccess(d, 5) = 10;       // 报错，给一个将亡值赋值 
````

为了让 `Access` 可以返回引用，需要在 `auto` 上加推导：

````c++
template <typename Container, typename Index>
decltype(auto) Access(Container& c, Index i)
{
    return c[i];
}
````

这样返回的就是一个左值引用了；

> PS：原书中还涉及了对于 `Container` 的完美转发问题，这里不展开；

使用 `decltype(auto)` 时，还有存在一个比较特殊的语法：

如果原来返回值是值类型，给返回值表达式加上 `()`，推导出引用：

```c++
decltype(auto) f1()
{
    int x = 0;
    …
    return x;                            //decltype(x）是int，所以f1返回int
}

decltype(auto) f2()
{
    int x = 0;
    return (x);                          //decltype((x))是int&，所以f2返回int&
}
```

`f2()` 返回一个局部成员的引用，这是很危险的，所以当使用`decltype(auto)`的时候一定要加倍的小心；



## 请记住

- `decltype` 总是不加修改的产生变量或者表达式的类型。
- 对于 `T` 类型的不是单纯的变量名的左值表达式，`decltype` 总是产出 `T` 的引用即`T&`。
- C++14支持 `decltype(auto)`，就像 `auto` 一样，推导出类型，但是它使用`decltype ` 的规则进行推导。

