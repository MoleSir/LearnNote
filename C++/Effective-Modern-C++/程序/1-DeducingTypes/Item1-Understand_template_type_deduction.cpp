/* 理解模板类型推导 */
#include <iostream>

int v = 12;
const int cv = 12;
const int& rv = v;

namespace situation_1 
{
    template <typename T>
    void f(T& param) {}

    void test()
    {
        f(v);           // T& --> int &, T --> int
        f(cv);          // T& --> const int&, T --> const int
        f(rv);          // T& --> const int&, T --> const int
        // f(12);
    }
}

namespace situation_2
{
    template <typename T>
    void f(T&& param) {}

    void test()
    {
        f(v);           // T&& -> int&, T --> int&
        f(cv);          // T&& -> const int&, T --> const int&
        f(rv);          // T&& -> const int&, T --> const int&
        f(23);          // T&& -> T&&, T --> int
    }
} 

namespace situation_3
{
    template <typename T>
    void f(T param) {}

    void test()
    {
        f(v);           // T -> int
        f(cv);          // T -> int
        f(rv);          // T -> int
    }
} 

namespace situation_array
{
    template <typename T>
    void f1(T param) {}

    template <typename T>
    void f2(T& param) {}

    void test()
    {
        const char str[] = "adasdasdsadasdaferkl";
    
        f1(str);            // T --> const char*
        f2(str);            // T --> const char[N], N 为数组长度
    }

    // 获取数组长度
    template <typename T, std::size_t N>
    constexpr std::size_t GetArrayLength(T (&)[N]) noexcept
    {
        return N;
    }
} 


int main()
{
    situation_1::test();
    situation_2::test();
    situation_3::test();
    
    int numbers[] = {12, 43, 65, 87686, 45, 7878, 89898};
    std::cout << situation_array::GetArrayLength(numbers) << std::endl;


    return 0;
}