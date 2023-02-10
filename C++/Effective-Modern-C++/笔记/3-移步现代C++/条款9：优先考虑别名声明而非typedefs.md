# 条款 9：优先考虑别名声明而非`typedef`s

​		Item 9: Prefer alias declarations to `typedef`s.

## `using` 更加直观

没有使用模板时，`typdef` 与 `using` 对于类型定义的作用基本相同：

````c++
typedef std::unique_ptr<std::unorderd_map<std::string, std::string>> UPtrMapSS;
using UPtrMapSS = std::unique_ptr<std::unorderd_map<std::string, std::string>>;
````

PS：个人认为 `using` 看着就直观很多，特别是对函数指针的定义：

```c++
typedef int (*handler_t) (int, const std::string&);
using handler_t = int (*) (int, const std::string&)l
```



## `using` 可以带模板

当出现模板，`using` 就比 `typedef` 强大得多，`using` 可以直接绑定模板参数，而 `typdef` 不能：

````c++
template <typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;

MyAllocList<Widget> lw;
````

但对 `typdef`，十分繁琐：

````c++
template<typename T>                          
struct MyAllocList {                          
    typedef std::list<T, MyAlloc<T>> type;       
};

MyAllocList<Widget>::type lw;        
````

并且，如果如果想要使用 `typedef` 得到的类型，因为这带有模板，需要使用 `typename` 明确指出这个类型：

````c++
template<typename T>
class Widget {                              
private:                                    
    typename MyAllocList<T>::type list;   
}; 
````

而使用别名声明定义一个`MyAllocList`，就不需要使用`typename`：

````c++
template<typename T>
class Widget {                              
private:                                    
    MyAllocList<T> list;
}; 
````

因为 `MyAllocList` 如果使用 `using` 定义，就是一个别名模板，肯定是某个类型；

但使用 `typedef` 时，由于需要使用类加 `::` 取出，并且不能完成确定这个是一个类型。因为可能存在一个`MyAllocList`的它们没见到的特化版本，那个版本的`MyAllocList<T>::type`指代了一种不是类型的东西；



## 请记住

- `typedef`不支持模板化，但是别名声明支持。
- 别名模板避免了使用“`::type`”后缀，而且在模板中使用`typedef`还需要在前面加上`typename`；