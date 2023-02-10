## 条款 21：优先考虑使用`std::make_unique`和`std::make_shared`，而非直接使用`new`

​		Item 21: Prefer `std::make_unique` and `std::make_shared` to direct use of `new`

`std::make_unique`和`std::make_shared` 接收任意的多参数集合，完美转发到构造函数去动态分配一个对象，然后返回这个指向这个对象的指针；

使用 `make` 函数有诸多好处：



## 避免重复代码

使用 `make` 创建智能指针时可以可以使用 `auto`，避免重复写类名称：

````c++
auto upw1(std::make_unique<Widget>());      //使用make函数
std::unique_ptr<Widget> upw2(new Widget);   //不使用make函数
auto spw1(std::make_shared<Widget>());      //使用make函数
std::shared_ptr<Widget> spw2(new Widget);   //不使用make函数
````

避免重复代码，源代码中的重复增加了编译的时间，会导致目标代码冗余，并且通常会让代码库使用更加困难；



## 异常安全

考虑这样两个函数：

````c++
void processWidget(std::shared_ptr<Widget> spw, int priority);
int computePriority();
````

使用 `new` 直接创建对象：

```c++
processWidget(std::shared_ptr<Widget>(new Widget), 
              computePriority());
```

实参必须被完全准备好，才进入 `processWidget`，需要三步：

- `new` 成功；
- 创建 `std::shared_ptr` 对象成功；
- 执行 `computePriority` 成功；

而 C++ 生成目标代码时，不保证顺序，可能按照这个顺序执行：

- `new Widget` ；
- 执行 `computePriority` 成功；
- 创建 `std::shared_ptr` 对象；

如果 `computePriority` 异常，导致 `Widget` 对象被创建但没有被管理，内存泄露；

使用 `make` 就可以解决：

````c++
processWidget(std::make_shared<Widget>(),
              computePriority());
````

两个函数总有一个被调用，不管哪个，内存总是会被保护；



## 提高效率

`std::make_shared` 与直接使用 `new` 效率提升，允许编译器生成更小，更快的代码，并使用更简洁的数据结构；

````c++
std::shared_ptr<Widget> spw(new Widget);
````

这句代码执行了两次内存分配，一次对 `Widget` 对象，一次申请控制块；

如果使用`std::make_shared`代替：

````c++
auto spw = std::make_shared<Widget>();
````

会分配一块内存，同时容纳了`Widget`对象和控制块；



## 缺点

### 无法指定删除器

有些情况下 `make` 不能或不应该被使用。

`make`函数都不允许指定自定义删除器，如果想定义删除器，只能使用 `new`；

### 无法明确对象创建法则

如果类用有 `initializer_list` 的重载构造，使用 `{}` 总是倾向于调用这个版本；

如果使用 `make` 创建对象，就不能明确指定使用 `()` 还是 `{}`；在 `make` 函数中，选择了使用 `()` ；

所以如果想使用 `{}` 创建对象，只能用 `new`；

### 无法精确分配内存

某些类重载 `operator new` 与 `operator delete`，意味着对这些类型的对象的全局内存分配和释放是不合常规的；

而 `make` 申请的内存大小不是类对象的大小，还会加上控制器，不发用类重载的 `operator new` 申请；



## 请记住

- 和直接使用`new`相比，`make`函数消除了代码重复，提高了异常安全性。对于`std::make_shared`和`std::allocate_shared`，生成的代码更小更快。
- 不适合使用`make`函数的情况包括需要指定自定义删除器和希望用花括号初始化。
- 对于`std::shared_ptr`s，其他不建议使用`make`函数的情况包括(1)有自定义内存管理的类；(2)特别关注内存的系统，非常大的对象，以及`std::weak_ptr`s比对应的`std::shared_ptr`s活得更久。