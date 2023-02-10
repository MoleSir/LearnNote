# 条款 16：让`const`成员函数线程安全

​		Item 16: Make `const` member functions thread safe

`const` 函数说明此函数不改变成员的值，那么应该来说其本身就是线程安全的；但也有例外；



## `const` 成员函数但非线程安全

有一个用来表示多项式的类；次类中拥有一个计算根的函数；

根的计算十分复杂，对一个多项式来说，直到需要使用根才计算，并且只计算一次，得到结果后就保存：

````c++
class Polynomial{
public:
    using RootsType = std::vector<double>;
	RootsType roots() const
    {
        if (!rootsAreValid) { // 判断是否计算过
            //计算
            rootsAreValid = true;
        }
        return rootVals;
	}
    ...
private:
    mutable bool rootsAreValid{ false };
    mutable RootsType rootVals{};
    ...
};
````

如果两个线程同时调用一个对象的 `roots`：

````c++
Polynomial p;
…

/*------ Thread 1 ------*/      /*-------- Thread 2 --------*/
auto rootsOfp = p.roots();      auto valsGivingZero = p.roots();
````

`roots `是 `const` 成员函数，那就表示着它是一个读操作。在没有同步的情况下，让多个线程执行读操作是安全的。它最起码应该做到这点；

但这个例子中线程不安全；因为成员变量 `rootsAreValid` 和 `rootVals` 可能被修改；



## 使用 `std::mutex` 解决

可以使用 `mutex` 解决：

````c++
class Polynomial {
public:
    using RootsType = std::vector<double>;
    RootsType roots() const
    {
        std::lock_guard<std::mutex> g(m);     
        if (!rootsAreValid) {                 
            ...                  
            rootsAreValid = true;
        }
        return rootsVals;
    }                                          
private:
    mutable std::mutex m;
    mutable bool rootsAreValid { false };
    mutable RootsType rootsVals {};
};
````

`std::mutex` 是只可移动类型，即只能移动不能复制；所以这导致拥有 `std::mutex` 的类不能拷贝，只能移动；



## 使用 `std::atomic` 解决

如果想计算函数被调用了多少次，可以尝试使用 `std::atomic` ：

````c++
class Point {                                   
public:
    double distanceFromOrigin() const noexcept
    {                                         				    ++callCount;                          
        return std::sqrt((x * x) + (y * y));
    }
private:
    mutable std::atomic<unsigned> callCount{ 0 };
    double x, y;
};
````

`std::atomic ` 是只可移动类型，所以在 `Point` 中存在 `callCount` 就意味着`Point` 也是只可移动的；

对`std::atomic`变量的操作通常比互斥量的获取和释放的消耗更小；但是有时只能使用 `std::mutex`，例如：

````c++
class Widget {
public:
    …
    int magicValue() const
    {
        if (cacheValid) return cachedValue;
        else {
            auto val1 = expensiveComputation1();
            auto val2 = expensiveComputation2();
            cachedValue = val1 + val2;              //第一步
            cacheValid = true;                      //第二步
            return cachedValid;
        }
    }
private:
    mutable std::atomic<bool> cacheValid{ false };
    mutable std::atomic<int> cachedValue;
};
````

用两个 `std::atomic` 对象保证线程安全；但这里只能保证 `cacheValid`  与 `cachedValue` 不可中断，程序可能在 `cachedValue = val1 + val2;   ` 之前被打断，此时虽然已经完成了两个复杂值的大部分计算，但另一个线程看来，`cacheValid` 为 `false`，还是会再次计算一次；

这种情况下，使用 `std::mutex` 才更合理：

````c++
class Widget {
public:
    …
    int magicValue() const
    {
        std::lock_guard<std::mutex> guard(m);   //锁定m
        
        if (cacheValid) return cachedValue;
        else {
            auto val1 = expensiveComputation1();
            auto val2 = expensiveComputation2();
            cachedValue = val1 + val2;
            cacheValid = true;
            return cachedValue;
        }
    }                                           //解锁m
    …

private:
    mutable std::mutex m;
    mutable int cachedValue;                    //不再用atomic
    mutable bool cacheValid{ false };           //不再用atomic
};

````



## 请记住

- 确保`const`成员函数线程安全，除非你**确定**它们永远不会在并发上下文（*concurrent context*）中使用。
- 使用`std::atomic`变量可能比互斥量提供更好的性能，但是它只适合操作单个变量或内存位置。

