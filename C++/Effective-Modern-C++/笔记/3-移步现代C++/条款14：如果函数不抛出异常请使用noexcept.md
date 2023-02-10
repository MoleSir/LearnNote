# 条款 14：如果函数不抛出异常请使用`noexcept`

​		Item 14: Declare functions `noexcept` if they won’t emit exceptions

C++98 允许在函数后加上可能抛出的异常类型，如果不抛出，加上 `throw()`；而C++11 增加了 `noexcept` 关键字表示函数不跑出异常；



## 生成更好的代码

给不抛异常的函数加上`noexcept`的可以让编译器生成更好的目标代码。

````c++
int f(int x) throw();   //C++98风格，没有来自f的异常
int f(int x) noexcept;  //C++11风格，没有来自f的异常
````

如果在运行时，`f` 出现一个异常，那么就和`f`的异常说明冲突了。在C++98的异常说明中，调用栈（the *call stack*）会展开至`f`的调用者，在一些与这地方不相关的动作后，程序被终止。C++11异常说明的运行时行为有些不同：调用栈只是**可能**在程序终止前展开。

展开调用栈和**可能**展开调用栈两者对于代码生成（code generation）有非常大的影响。在一个`noexcept`函数中，当异常可能传播到函数外时，优化器不需要保证运行时栈（the runtime stack）处于可展开状态；也不需要保证当异常离开`noexcept`函数时，`noexcept`函数中的对象按照构造的反序析构。而标注“`throw()`”异常声明的函数缺少这样的优化灵活性，没加异常声明的函数也一样。可以总结一下：

````c++
RetType function(params) noexcept;  //极尽所能优化
RetType function(params) throw();   //较少优化
RetType function(params);           //较少优化
````

PS：这段话专业性比较强，直接复制的原文；



## 对移动构造的无异常保证

向一个 `std::vector` 中插入数据，如果 `vector` 空间不足，会申请一个大块内存，并且将原有的数据复制过去，再析构原来的数据；

即使在复制过程中某个元素的拷贝构造抛出异常，由于此时没有完全复制完毕，那么旧内存空间还保存着原有的所有数据。可以还原到原状态，保证异常安全；

C++ 11 1引入了高效率的移动构造，如果用移动构造来解决 `vector` 空间不足时复制元素带来的开销，可能造成异常安全被破坏；

因为只要一个元素的移动构造完成，旧内存空间的数据被破坏，移动到了新内存。如果某个移动构造发生异常，没有办法将 `vector` 还原；

所以 `std::vector` 的做法是：如果可以就移动，如果必要则复制；

先检查元素的移动构造是否是 `noexcept` 的；



## `swap` 函数

`swap` 函数很重要，所以希望是 `noexcept` 的；标准库的`swap`是否`noexcept`有时依赖于用户定义的`swap`是否`noexcept`。比如，数组和`std::pair`的`swap`声明如下：

````c++
template <class T, size_t N>
void swap(T (&a)[N],
          T (&b)[N]) noexcept(noexcept(swap(*a, *b)));  
template <class T1, class T2>
struct pair {
    …
    void swap(pair& p) noexcept(noexcept(swap(first, p.first)) &&
                                noexcept(swap(second, p.second)));
};
````

这些函数**视情况 **`noexcept`：它们是否`noexcept`依赖于`noexcept`声明中的表达式是否`noexcept`；

因为如果函数不提供`noexcept`保证，其它依赖这个函数的高层次`swap`就不能保证`noexcept`；



## 默认 `noexcept`

对于一些函数，使其成为`noexcept`是很重要的，它们应当默认如是;

在C++98，允许内存释放（memory deallocation）函数（即`operator delete`和`operator delete[]`）和析构函数抛出异常是糟糕的代码设计，C++11将这种作风升级为语言规则；

默认情况下，内存释放函数和析构函数——不管是用户定义的还是编译器生成的——都是隐式`noexcept`。



## 请记住

- `noexcept`是函数接口的一部分，这意味着调用者可能会依赖它
- `noexcept`函数较之于non-`noexcept`函数更容易优化
- `noexcept`对于移动语义，`swap`，内存释放函数和析构函数非常有用
- 大多数函数是异常中立的（译注：可能抛也可能不抛异常）而不是`noexcept`