## 条款 10：优先考虑限域 `enum` 而非未限域 `enum`

​		Item 10: Prefer scoped `enum`s to unscoped `enum`s

## 限域 `enum`

C++98风格的 `enum` 中声明的枚举，作用域范围在包含这个 `enum` 的作用域，这意味着作用域内不能含有相同名字的其他东西：

````c++
enum Color { black, white, red };
auto white = false;
````

C++11 有限域枚举(*scoped `enum`*)，它不会导致枚举名泄漏：

```c++
enum class Color { black, white, red };
auto white = false;
Color c = red; // 错误，作用域中没有存在 red
Color c = Color::white; // 正确
```



## 禁止隐式类型转换

并且限域 `enum` 还有一个特性：在它的作用域中，枚举名是强类型。而未限域`enum `中的枚举名会隐式转换为整型：

````c++
enum Color { black, white, red };       //未限域enum
std::vector<std::size_t>                //func返回x的质因子
  primeFactors(std::size_t x);
Color c = red;

if (c < 14.5) {                         // Color与double比较 (!)
    auto factors =                      // 计算一个Color的质因子(!)
      primeFactors(c);
    …
}
````

使用 `enum class` 后就不能进行隐式类型转换：

````c++
enum class Color { black, white, red }; //Color现在是限域enum
Color c = Color::red;                   //和之前一样，只是
...                                     //多了一个域修饰符

if (c < 14.5) {                         //错误！不能比较
                                        //Color和double
    auto factors =                      //错误！不能向参数为std::size_t
      primeFactors(c);                  //的函数传递Color参数
    …
}
````

如果真的需要类型转换，明确指出转换类型：

````c++
if (static_cast<double>(c) < 14.5) {   
    auto factors =                                  
      primeFactors(static_cast<std::size_t>(c));  
}
````



## 可以前置声明

限域 `enum `还有第三个好处：可以被前置声明；也就是说，它们可以不指定枚举名直接声明：

````c++
enum Color;		// 错误
enum class Color;  // ok
````

文件之间通过声明式联系，可以减少编译依赖；



## 可以手动指定类型

最后，相比非限域`enum`，限域`enum` 底层类型可以手动指定，默认不指定就是 `int`：

````cpp
enum class Status;                  //底层类型是int
enum class Status: std::uint32_t;   //Status的底层类型
                                    //是std::uint32_t
                                    //（需要包含 <cstdint>）
````

当然，限域`enum` 也有缺点，需要明确指出类型加 `::`，可能在某些场合比较繁琐；



## 请记住

- C++98的`enum`即非限域`enum`。
- 限域`enum`的枚举名仅在`enum`内可见。要转换为其它类型只能使用*cast*。
- 非限域/限域`enum`都支持底层类型说明语法，限域`enum`底层类型默认是`int`。非限域`enum`没有默认底层类型。
- 限域`enum`总是可以前置声明。非限域`enum`仅当指定它们的底层类型时才能前置。