# 第6章 *lambda*表达式

​		CHAPTER 6 Lambda Expressions

*lambda* 表达式是 C++ 编程中的游戏规则改变者。这有点令人惊讶，因为它没有给语言带来新的表达能力。*lambda* 可以做的所有事情都可以通过其他方式完成。但是 *lambda* 是创建函数对象相当便捷的一种方法，对于日常的C++开发影响是巨大的。没有*lambda*时，STL中的“`_if`”算法（比如，`std::find_if`，`std::remove_if`，`std::count_if`等）通常需要繁琐的谓词，但是当有*lambda*可用时，这些算法使用起来就变得相当方便。用比较函数（比如，`std::sort`，`std::nth_element`，`std::lower_bound`等）来自定义算法也是同样方便的。在STL外，*lambda*可以快速创建`std::unique_ptr`和`std::shared_ptr`的自定义删除器，并且使线程API中条件变量的谓词指定变得同样简单。除了标准库，*lambda*有利于即时的回调函数，接口适配函数和特定上下文中的一次性函数。*lambda*确实使 C++ 成为更令人愉快的编程语言。

与*lambda*相关的词汇可能会令人疑惑，这里做一下简单的回顾：

- *lambda* 表达式（*lambda expression*）就是一个表达式。下面是部分源代码。在

    ````c++
    std::find_if(container.begin(), container.end(),
                 [](int val){ return 0 < val && val < 10; });   //译者注：本行高亮
    ````

    中，代码的高亮部分就是*lambda*。

- **闭包**（*enclosure*）是*lambda*创建的运行时对象。依赖捕获模式，闭包持有被捕获数据的副本或者引用。在上面的`std::find_if`调用中，闭包是作为第三个实参在运行时传递给`std::find_if`的对象。

- **闭包类**（*closure class*）是从中实例化闭包的类。每个*lambda*都会使编译器生成唯一的闭包类。*lambda*中的语句成为其闭包类的成员函数中的可执行指令。

*lambda*通常被用来创建闭包，该闭包仅用作函数的实参。上面对`std::find_if`的调用就是这种情况。然而，闭包通常可以拷贝，所以可能有多个闭包对应于一个*lambda*。比如下面的代码：

````c++
{
    int x;                                  //x是局部对象
    …

    auto c1 =                               //c1是lambda产生的闭包的副本
        [x](int y) { return x * y > 55; };

    auto c2 = c1;                           //c2是c1的拷贝

    auto c3 = c2;                           //c3是c2的拷贝
    …
}
````

`c1`，`c2`，`c3`都是*lambda*产生的闭包的副本。

非正式的讲，模糊*lambda*，闭包和闭包类之间的界限是可以接受的。但是，在随后的Item中，区分什么存在于编译期（*lambdas* 和闭包类），什么存在于运行时（闭包）以及它们之间的相互关系是重要的。