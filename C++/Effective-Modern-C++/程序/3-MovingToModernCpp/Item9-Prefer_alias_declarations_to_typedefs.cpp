#include <iostream>
#include <string>

// 指针
using handler = int (*) (double, std::string& str);
typedef int (*handler_t) (int, double, float, char);


template <typename valueType, typename AllocType>
class Container {};
class MyAlloc {};

// 模板类型
template <typename valueType>
using C1 = Container<valueType, MyAlloc>;

template <typename valueType>
struct C2
{
    typedef type Container<valueType, MyAlloc>; 
}

int main()
{   
    
    return 0;
}