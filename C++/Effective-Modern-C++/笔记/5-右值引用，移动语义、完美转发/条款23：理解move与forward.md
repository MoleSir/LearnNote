# 条款 23：理解`std::move`和`std::forward`

​		Item 23: Understand `std::move` and `std::forward`

## `move` 与 `forward` 的本质

`std::move`不移动（move）任何东西，`std::forward`也不转发（forward）任何东西。在运行时，它们不做任何事情。它们不产生任何可执行代码，一字节也没有；

仅仅是执行转换（cast）的函数（事实上是函数模板）：

- `std::move`无条件的将它的实参转换为右值；
- `std::forward`只在特定情况满足时下进行转换；



## `move` 的实现

下面是 C++ 11 中很接近标准 `std::move` 的实现：

````c++
template <typename T>
typename remove_reference<T>::type&&
move(T&& prarm)
{
    using ReturnType = 
        typename remove_reference<T>::type&&;
   	return static_cast<ReturnType>(param);
}
````

传入的参数经过万能引用计算出 `T`，最后去掉 `T` 的所有引用，得到纯粹的类型，最后加上 `&&`，称为右值引用，最后转型返回；

并且 `const` 等属性是不会被去掉的；

所以 `std::move` 只是转型，没有做其他任何事情；



## 常见的错误

考虑这样的代码：

````c++
class Object
{
public:
	Object(const std::string& text)
    	: _text(std::move(text))
    {...}
    ...
private:
	std::string _text;
};
````

希望在创建 `Object` 的时候，可以传入任意类型的 `std::string`，因为 `const std::string&` 可以接受任何类型；

并且为了节约开销，希望使用 `std::string` 的移动构造，只需要申请一次内存；

````c++
Object obj(std::string("hello"));
````

但结果是无论传入什么实参，最后 `_text(std::move(text))` 都调用了拷贝 构造；

因为 `std::move` 不会改变 `const`，而 `text` 明明白白的写在形参中是 `const std::string&`，结果移动后，成为 `const std::string&&`；

只能匹配到构造函数。所以：

- 不要在希望能移动对象的时候，声明他们为 `const`。对 `const` 对象的移动请求会悄无声息的被转化为拷贝操作；
- `std::move` 不仅不移动任何东西，而且它也不保证它执行转换的对象可以被移动。关于`std::move`，能确保的唯一一件事就是将它应用到一个对象上，能够得到一个右值。



## `forward`

`std::forward` 最常见的情景是一个模板函数，接收一个通用引用形参，并将它传递给另外的函数：

````c++
void process(const Widget& lvalArg);
void process(Widget&& rvalArg);
template <typename T>
void logAndProcess(T&& param)
{
    auto now = std::chrono::system_clock::now();
    
    makeLogEntry("Calling 'process'", now);
    process(std::forward<T>(param));
}
````

如果不加 `std::forward` ，那么 `process` 的调用永远都是左值版本；因为 `param` 形参本身就是左值；

而 `std::forward` 可以区分 `param` 传入的实参到底是左值还是右值，关键信息就是根据 `T` 判断；



## 请记住

- `std::move`执行到右值的无条件的转换，但就自身而言，它不移动任何东西。
- `std::forward`只有当它的参数被绑定到一个右值时，才将参数转换为右值。
- `std::move`和`std::forward`在运行期什么也不做。

