## 条款 15：尽可能的使用`constexpr`

​		Item 15: Use `constexpr` whenever possible

## `constexpr` 对象

`constexpr` 对象是编译器可知的，可以保存在只读空间中；

````c++
int sz;                             //non-constexpr变量
…
constexpr auto arraySize1 = sz;     //错误！sz的值在
                                    //编译期不可知
std::array<int, sz> data1;          //错误！一样的问题
constexpr auto arraySize2 = 10;     //没问题，10是
                                    //编译期可知常量
std::array<int, arraySize2> data2;  //没问题, arraySize2是constexpr
````

`const` 不提供 `constexpr` 所能保证之事，因为 `const` 对象不需要在编译期初始化它的值；

````c++
int sz;                            //和之前一样
…
const auto arraySize = sz;         //没问题，arraySize是sz的const复制
std::array<int, arraySize> data;   //错误，arraySize值在编译期不可知
````



## `constexpr` 函数

- `constexpr` 函数可以用于计算编译期常量。如果传给 `constexpr` 函数的实参在编译期可知，那么结果将在编译期计算。如果实参的值在编译期不知道，代码就会被拒绝；
- 当一个 `constexpr` 函数被一个或者多个编译期不可知值调用时，它就像普通函数一样，运行时计算它的结果；

例如 `constexpr` 函数 `pow`：

````c++
constexpr auto numConds = 5;                //（上面例子中）条件的个数
std::array<int, pow(3, numConds)> results;  //结果有3^numConds个元素
````

`pow` 的两个实参：`3` 与 `numConds` 都是编译器常量，那么 `pow` 函数得到的结果就是编译常量；否则 `pow` 将在允许时期计算；

C++11 中，`constexpr` 函数的代码只能有一句 `return`，当然可以使用三元运算符与递归拓展功能：

````c++
constexpr int pow(int base, int exp) noexcept
{
    return (exp == 0 ? 1 : base * pow(base, exp - 1));
}
````

在C++14中，`constexpr`函数的限制变得非常宽松了：

````c++
constexpr int pow(int base, int exp) noexcept   //C++14
{
    auto result = 1;
    for (int i = 0; i < exp; ++i) result *= base;   
    return result;
}
````



## `constexpr` 成员函数

`constexpr` 函数限制为只能获取和返回字面值类型，这些值可能在编译器决定；

在C++11中，除了`void`外的所有内置类型，以及一些用户定义类型都可以是字面值类型，因为构造函数和其他成员函数可能是`constexpr`：

````c++
class Point {
public:
    constexpr Point(double xVal = 0, double yVal = 0) noexcept
    : x(xVal), y(yVal)
    {}

    constexpr double xValue() const noexcept { return x; } 
    constexpr double yValue() const noexcept { return y; }

    void setX(double newX) noexcept { x = newX; }
    void setY(double newY) noexcept { y = newY; }

private:
    double x, y;
};
````

`Point`的构造函数可被声明为`constexpr`，因为如果传入的参数在编译期可知，`Point`的数据成员也能在编译器可知。因此这样初始化的`Point`就能为`constexpr`：

````c++
constexpr Point p1(9.4, 27.7);  //没问题，constexpr构造函数
                                //会在编译期“运行”
constexpr Point p2(28.8, 5.3);  //也没问题
````

并且 `xValue` 与 `yValue` 也是 `constexpr` 函数，那么对一个编译器期已知的 `Point` 对象，调用成员函数的 `getter`，使得 `x`、`y`在编译器可知：

````c++
constexpr 
Point midpoint(const Point& p1, const Point& p2) noexcept
{
    return { (p1.xValue() + p2.xValue()) / 2, 
           	 (p1.yValue() + p2.yValue()) / 2};
}
constexpr auto mid = midpoint(p1, p2);
````

将运行时期的运行并入编译期间，运行更快；

C++11 中 `constexpr` 成员函数是隐式的 `const`，所以 `setter` 函数不可以是 `constexpr`；但 C++14 是可以的；

`constexpr` 对象和 `constexpr` 函数可以使用的范围比 non-`constexpr` 对象和 函数大得多。使用 `constexpr` 关键字可以最大化对象和函数可以使用的场景；



## 记住

- `constexpr`对象是`const`，它被在编译期可知的值初始化
- 当传递编译期可知的值时，`constexpr`函数可以产出编译期可知的结果
- `constexpr`对象和函数可以使用的范围比non-`constexpr`对象和函数要大
- `constexpr`是对象和函数接口的一部分