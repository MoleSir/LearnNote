#include <iostream>
#include <cmath>

// C++98
class NonCopyObject1
{
public:
    NonCopyObject1() {}
private:
    NonCopyObject1(const NonCopyObject1&) {}
    NonCopyObject1& operator = (const NonCopyObject1&) { return *this; }
};

// C++11
class NonCopyObject2
{
public:
    NonCopyObject2() {}
private:
    NonCopyObject2(const NonCopyObject2&) = delete;
    NonCopyObject2& operator = (const NonCopyObject2&) = delete;
};

// 作用全局函数
bool isPrime(int x)
{
    if (x == 1 || x == 2 || x == 0) return true;
    for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0) return true;
    return false;
}
// 删除
bool isPrime(bool) = delete;
bool isPrime(double) = delete;
bool isPrime(char) = delete;

// 删除模板的特化
template <typename T>
void ProcessPointer(T* ptr)
{
    std::cout << "do somthing\n";
}
template <>
void ProcessPointer(const char* ) = delete;
template <>
void ProcessPointer(void* ) = delete;

int main()
{
    NonCopyObject1 obj1(); 
    // NonCopyObject1 obj2 = obj1;
    NonCopyObject2 obj2();
    // NonCopyObject2 obj3 = obj2;

    //isPrime('a');
    //isPrime(12.2);


    return 0;
}