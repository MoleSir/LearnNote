# 条款 8：优先考虑 `nullptr` 而非 `0` 和 `NULL`

​		Item 8: Prefer `nullptr` to `0` and `NULL`.

C++的解析策略是把`0` 与 `NULL` 看做`int`而不是指针：

````c++
void f(int);        //三个f的重载函数
void f(bool);
void f(void*);
f(0);               //调用f(int)而不是f(void*)
f(NULL);            //可能不会被编译，一般来说调用f(int)，
                    //绝对不会调用f(void*)
````

`nullptr `的真正类型是 `std::nullptr_t`，在一个完美的循环定义以后，`std::nullptr_t`又被定义为`nullptr`。可以隐式转换为指向任何内置类型的指针；

````c++
f(nullptr);         //调用重载函数f的f(void*)版本
````

并且使用 `nullptr` 表示空指针，对代码阅读者更加直观，不会产生歧义；

而对于函数模板推导时也是这样，C++ 总是把 `0` 与 `NULL` 解释为 `int`；



## 请记住

- 优先考虑`nullptr`而非`0`和`NULL`
- 避免重载指针和整型

