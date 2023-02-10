## 条款 19：对于共享资源使用`std::shared_ptr`

​		Item 19: Use `std::shared_ptr` for shared-ownership resource management

## `shared_ptr` 介绍

`std::shared_ptr` 通过引用计数（*reference count*）来确保它是否是最后一个指向某种资源的指针，关联资源并跟踪有多少 `std::shared_ptr` 指向该资源；

`std::shared_ptr`构造函数递增引用计数值（移动构造不会），析构函数递减值；

如果 `std::shared_ptr` 在计数值递减后发现引用计数值为零，没有其他`std::shared_ptr `指向该资源，它就会销毁资源。

但引用计数暗示着性能问题：

- **`std::shared_ptr` 大小是原始指针的两倍**，因为它内部包含一个指向资源的原始指针，还包含一个指向资源的引用计数值的原始指针；
- **引用计数的内存必须动态分配**。
- **递增递减引用计数必须是原子性的**。原子操作通常比非原子操作要慢；



## 删除器

`std::shared_ptr` 也可以指定删除器，不同于 `std::unique_ptr`，`std::shared_ptr`的设计更为灵活，删除器的类型不需要放入模板中：

````c++
auto loggingDel = [](Widget *pw){
                      makeLogEntry(pw);
                      delete pw;
                  };

std::unique_ptr<                        //删除器类型是
    Widget, decltype(loggingDel)        //指针类型的一部分
    > upw(new Widget, loggingDel);
std::shared_ptr<Widget>                 //删除器类型不是
    spw(new Widget, loggingDel);        //指针类型的一部分
````

这样的设计使得两个指向相同类型但不同删除器的 `std::shared_ptr` 的类型相同，可以放入同一个容器：

````c++
auto customDeleter1 = [](Widget *pw) { … };     //自定义删除器，
auto customDeleter2 = [](Widget *pw) { … };     //每种类型不同
std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
std::shared_ptr<Widget> pw2(new Widget, customDeleter2);
std::vector<std::shared_ptr<Widget>> vpw{ pw1, pw2 };
````



## 内存布局

指定自定义删除器不会改变 `std::shared_ptr` 对象的大小，一个`std::shared_ptr`对象都是两个指针大小；

而函数对象的数据会放在一个堆上，不属于 `std::shared_ptr` 对象的一部分；

一个 `std::shared_ptr` 对象中，一个指针指向持有的对象，另一个就指向这个堆空间，每个 `std::shared_ptr` 对象拥有一个这样的名为控制块的数据结构，上面放置着引用计数、删除器信息等内容；

![item19_fig1](.\pics\item19_fig1.png)

控制块的创建会遵循下面几条规则：

- **`std::make_shared`总是创建一个控制块**。它创建一个要指向的新对象，所以可以肯定`std::make_shared`调用时对象不存在其他控制块。

- **当从独占指针（即`std::unique_ptr`或者`std::auto_ptr`）上构造出`std::shared_ptr`时会创建控制块**。独占指针没有使用控制块，所以指针指向的对象没有关联控制块；

- **当从原始指针上构造出`std::shared_ptr`时会创建控制块**。使用原始指针创建 `shared_ptr` 时，会为这个空间创建一个控制块；

    所以要让两个 `shared_ptr` 指向同一内存，不可以用一个指针直接创建两个 `shared_ptr`，否则这个内存就有两个互相不影响的引用计数，导致被多次 `delete`；

    如果想指向同一内存，使用 `std::shared_ptr`或者`std::weak_ptr`作为构造函数实参，不会创建新控制块，而是指向原来那个，这样指向同一内存的 `shared_ptr` 对象使用同一个控制块，通过同一个引用计数管理内存；

违反第三条的例子：

````c++
auto pw = new Widget;                           //pw是原始指针
…
std::shared_ptr<Widget> spw1(pw, loggingDel);   //为*pw创建控制块
…
std::shared_ptr<Widget> spw2(pw, loggingDel);   //为*pw创建第二个控制块
````

两个独立的引用计数指向 `pw`，最后 `pw` 被删除两次；

总上，建议使用 `std::make_shared` 创建 `shared_ptr`，如果真的要使用原始指针初始化，直接用 `new` 出来的：

````c++
std::shared_ptr<Widget> spw1(new Widget, loggingDel);
std::shared_ptr<Widget> spw2(spw1);
````



## 使用建议

保持默认删除器，使用 `make_shared` 创建一个 `shared_ptr` 的开销并不大，对其解引用的开销也不会比原始指针多多少，但带来了很多好处；

但如果独占资源可行或者**可能**可行，用`std::unique_ptr`是一个更好的选择；

`unique_ptr` 可以直接转换为 `shared_ptr`，反之不行；

`std::shared_ptr`不能处理的另一个东西是数组；



## 请记住

- `std::shared_ptr`为有共享所有权的任意资源提供一种自动垃圾回收的便捷方式。
- 较之于`std::unique_ptr`，`std::shared_ptr`对象通常大两倍，控制块会产生开销，需要原子性的引用计数修改操作。
- 默认资源销毁是通过`delete`，但是也支持自定义删除器。删除器的类型是什么对于`std::shared_ptr`的类型没有影响。
- 避免从原始指针变量上创建`std::shared_ptr`。