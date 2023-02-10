# 条款十三：优先考虑`const_iterator` 而非`iterator`

​		Item 13: Prefer `const_iterators` to `iterators`

STL  `const_iterator `等价于指向常量的指针（pointer-to-`const`），都指向不能被修改的值。标准实践是能加上`const`就加上；

在 C++98 中，`const_iterator` 难以获取，并且 STL 对其支持度不高；但 C++11 的`const_iterator`既容易获取又容易使用。容器的成员函数`cbegin`和`cend`产出`const_iterator`；

````c++
std::vector<int> values;                             
auto it =                                            
	std::find(values.cbegin(), values.cend(), 1983);
values.insert(it, 1998);
````

C++ 11 有非成员函数版本的 `begin` 与 `end`，但没有非成员版的 `cbegin`，`cend`，`rbegin`，`rend`，`crbegin`，`crend`；C++14 都有；



## 请记住

- 优先考虑`const_iterator`而非`iterator`
- 在最大程度通用的代码中，优先考虑非成员函数版本的`begin`，`end`，`rbegin`等，而非同名成员函数；