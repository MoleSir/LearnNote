# 条款 2：理解 `auto` 类型推导

​		Item 2: Understand `auto` type deduction

`auto ` 类型推导的规则与模板类推导完全相同；

````c++
template <typename T>
void f(ParamType param);
f(expr);
````

在`f`的调用中，编译器使用`expr`推导`T`和`ParamType`的类型；

当一个变量使用 `auto` 进行声明时，`auto `扮演了模板中 `T` 的角色，变量的类型说明符扮演了 `ParamType` 的角色：

比如：

```c++
auto&& x = 12;
```

上述推导，就相当于 `ParamType = T&&`， `T = auto`，`expr = 12` 来推导 `ParamType` 与 `T`；

对 `auto` 的推导也是分成三种，规则跟条款 1 所见是相同的；

但它们也存在差异，`auto` 总是先假定花括号为初始化列表：

````c++
auto x = {25};
int y{3};
````

`x` 不会被推导为 `int`，而是一个  `std::initiallizer_list<int>` ，即使 C++ 运行用大括号给 `int`  初始化；

而模板参数推导并没有这个能力：

````c++
auto x = {12, 34, 12}; // 推导成功， auto = std::initiallizer_list<int>

template <typename T>
void f(T param);
f({12, 343 , 232});    // 错误，无法推导 T
````

必须在模板中明确指明 `initiallizer_list`：

````c++
template <typename T>
void f(std::initializer_list<T> initList);
f({45, 54, 555});		// T 为 int
````



## 请记住

- `auto` 类型推导通常和模板类型推导相同，但是 `auto` 类型推导假定花括号初始化代表 `std::initializer_list`，而模板类型推导不这样做
- 在C++14中`auto`允许出现在函数返回值或者*lambda*函数形参中，但是它的工作机制是模板类型推导那一套方案，而不是`auto`类型推导