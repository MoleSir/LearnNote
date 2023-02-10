# 条款 25：对右值引用使用`std::move`，对通用引用使用`std::forward`

​		Item 25: Use `std::move` on rvalue references, `std::forward` on universal references.

## `move` 与 `forward` 的适用场景

如果希望在移动构造中，让类中成员也进行移动构造，那么需要使用 `std::move`：

````c++
class Widget{
public:
    Widget(Widget&& rhs) : 
    	name(std::move(rhs.name)),
    	p(std::move(rhs.p))
        {...}
private:
    std::string name;
    std::shared_ptr<SomeDataStructure> p;
};
````

而如果使用通用引用，就需要配合 `std::forward`：

````c++
class Widget{
public:
    template <typename T>
    void setName(T&& newName) 
    { name = std::forward<T>(newName); }
};
````

总而言之，当把右值引用转发给其他函数时：

- 右值引用应该被无条件转换为右值（通过`std::move`），因为它们总是绑定到右值；
- 当转发通用引用时，通用引用应该有条件地转换为右值（通过`std::forward`），因为它们只是有时绑定到右值。



## 注意在最后一次适用再转发

如果在函数中，多次使用右值引用或者通用引用，那么就要在函数的最后才对它们施加 `std::move` 与 `std::forward` 来转发：

````c++
template<typename T>
void setSignText(T&& text)                  //text是通用引用
{
  sign.setText(text);                       //使用text但是不改变它
  
  auto now = 
      std::chrono::system_clock::now();     //获取现在的时间
  
  signHistory.add(now, 
                  std::forward<T>(text));   //有条件的转换为右值
}
````

先保证调用完 `setText` 后，`text` 不会被转移走，到最后再使用 `std::forward`；



## 返回值优化与 `move`

考虑这样的函数：

````c++
Matrix                             
operator+(Matrix&& lhs, const Matrix& rhs)
{
    lhs += rhs;
    return lhs;                     //拷贝lhs到返回值中
}
````

返回的是 `lhs`，那么编译器会调用拷贝构造将其拷贝到函数外；

而如果 `Matrix` 支持移动，并且移动构造效率更高，那么使用 `std::move` 会更好：

````c++
Matrix                             
operator+(Matrix&& lhs, const Matrix& rhs)
{
    lhs += rhs;
    return std::move(lhs);
}
````

即使没有移动构造，也会去乖乖调用拷贝；

### 没有 RVO

但不是对所有的返回值加上 `std::move` 都是更好的；

````c++
Widget makeWidget()                 //makeWidget的“拷贝”版本
{
    Widget w;                       //局部对象
    …                               //配置w
    return w;                       //“拷贝”w到返回值中
}
Widget obj = makeWidget();
````

函数中场景 `w`，调用一次构造函数，返回 `w` 到临时变量又调用一次构造函数；最后函数外承接临时变量 `w` 又需要一次移动构造函数；

一共三次构造，两次拷贝；

所以，可能会利用 `std::move` 来优化：

````c++
Widget makeWidget()                 //makeWidget的移动版本
{
    Widget w;
    …
    return std::move(w);         
}
Widget obj = makeWidget();
````

首先创建 `w` 一次构造，`return` 时，创建临时变量时使用的不是拷贝构造而是移动构造，最后在函数外再移动构造一次；

看起来确实开销小（如果移动构造开销小的话）；

### 有 RVO

但是这是在没有返回值优化的情况下，现在编译器都拥有返回值优化（*return value optimization*，RVO）；返回值优化的条件是：

- 局部对象与函数返回值的类型相同；
- 局部对象就是要返回的东西

显然，对没有 `std::move` 的版本，经过 RVO，最后只调用了一次构造函数，好像这个对象没有调用函数就被创建了；

而对后者，先调用构造函数创建 `w`，而在返回值时，不满足 RVO 条件 2，没有优化，还需要执行一次移动构造；

并且由于前者没有任何临时变量，所以不调用析构，而后者需要调用一次析构函数将



## 请记住

- 最后一次使用时，在右值引用上使用`std::move`，在通用引用上使用`std::forward`。
- 对按值返回的函数要返回的右值引用和通用引用，执行相同的操作。
- 如果局部对象可以被返回值优化消除，就绝不使用`std::move`或者`std::forward`。
