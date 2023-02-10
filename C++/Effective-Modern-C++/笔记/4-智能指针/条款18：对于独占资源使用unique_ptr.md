## 条款 18：对于独占资源使用`std::unique_ptr`

​		Item 18: Use `std::unique_ptr` for exclusive-ownership resource management.

## `std::unique_ptr` 介绍

需要一个智能指针时，`std::unique_ptr` 通常最合适；

默认情况下，`std::unique_ptr` 大小等同于原始指针，而且对于大多数操作（包括取消引用），他们执行的指令完全相同；

这意味着甚至可以在内存和时间都比较紧张的情况下使用它。

`std::unique_ptr` 体现了专有所有权语义：

- 一个非空的 `std::unique_ptr` 始终指向某个内容；
- 移动 `std::unique_ptr` 将所有权转移，原指针变成 `nullptr`；
- 拷贝一个`std::unique_ptr`是不允许的；



## 删除器

默认情况下，销毁将通过`delete`进行，但是在构造过程中，`std::unique_ptr`对象可以被设置为使用（对资源的）**自定义删除器**：当资源需要销毁时可调用的任意函数（或者函数对象，包括*lambda*表达式）；

````c++
// 创建删除器
auto delInvmt = [](Investment* pInvestment){
	makeLogEntry(pINvestment);
	delete pInvestment;
};
// 工厂函数
template <typename... Ts>
std::uniqu_ptr<Investment, decltype(delInvmt)>
    makeInvestment(Ts&&... params)
{
    std::unqiue_ptr<Investment, decltype(delInvmt)>
        pInv(nullptr, delInvmt);
   	// 根据条件创建对象
    if (...) 
        pInv.reset(new Stock(std::forward<Ts>(params)...));
    else if (...)
		pInv.reset(new Bond(std::forward<Ts>(params)...));	  else if (...)
        pInv.reset(new RealEstate(std::forward<Ts>(params)...));
    return pInv;
}
````

- 在 `std::unique_ptr` 的第二个模板参数指定删除器的类型，如果是 `lambda`，建议使用 `decltype` 自动生成；
- `makeInvestment` 先创建一个空的 `std::unique_str`，再使用 `rest` 赋值；
- 自定义删除器的形参是 `Investment*`，所以删除原始指针时，会将其视为 `Investment` 处理，实现析构函数的多态；

默认情况下，`std::unique_ptr` 大小与指针相同；

如果加入的删除器是某个函数，其大小会增加一个指针的大小来保存函数指针；

如果加入的删除器是 `lambda` 表达式，增大的大小取决于 `lambda` 表达式捕获变量的数量与大小，不捕获的话，对大小没有影响；



## 类型转换

`std::unique_ptr` 可以轻松高效的转换为 `std::shared_ptr`：

````c++
std::shared_ptr<Investment> sp =            //将std::unique_ptr
    makeInvestment(arguments);              //转为std::shared_ptr
````

所以工厂函数适合返回一个 `std::unique_ptr`，这样外部调用时可以灵活使用 `std::unique_ptr` 与 ``std::shared_ptr`；



## 请记住

- `std::unique_ptr`是轻量级、快速的、只可移动（*move-only*）的管理专有所有权语义资源的智能指针
- 默认情况，资源销毁通过`delete`实现，但是支持自定义删除器。有状态的删除器和函数指针会增加`std::unique_ptr`对象的大小
- 将`std::unique_ptr`转化为`std::shared_ptr`非常简单
