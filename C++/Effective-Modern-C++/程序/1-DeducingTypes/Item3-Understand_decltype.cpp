#include <iostream>
#include <string>

struct Object
{
    Object() 
    {
        std::cout << this << " object constructed\n";
    }
    ~Object()
    {
        std::cout << this << " object destructed\n";
    }
    int a = 0;
};

Object GetObject()
{
    Object o;
    return o;
}


// 简单一个容器
template <typename T>
class Array
{
    using value_t = T;
public:
    Array(std::size_t size, value_t value) : _handler(nullptr), _size(size)
    {
        try
        {
            this->_handler = new value_t[size];  
        }
        catch(std::bad_alloc& e)
        {
            std::cout << e.what() << std::endl;
            return;
        }
        for (int i = 0; i < size; i++)
            this->_handler[i] = value;
    }
    Array(const Array& that) = delete;
    Array& operator = (const Array& that) = delete;
    Array(Array&& that) = delete;
    Array& operator = (Array&&) = delete;

    ~Array()
    {
        delete[] this->_handler;
    }

    value_t& operator [] (std::size_t index) const
    {
        return this->_handler[index];
    } 

    void Print() const
    {
        for (int i = 0; i < this->_size; ++i)
            std::cout << this->_handler[i] << ", ";
        putchar('\n');
    }

private:
    value_t* _handler;
    std::size_t _size;
};

// C++ 11 版本
template <typename Container>
auto Access1(Container& c, std::size_t i) -> decltype(c[i])
{
    return c[i];
}

// 由 auto 推导，是一个拷贝
template <typename Container>
auto Access2(Container& c, std::size_t i)
{
    return c[i];
}

// C++ 14 的 decltype(auto) 功能推导返回值
template <typename Container>
decltype(auto) Access3(Container& c, std::size_t i)
{
    return c[i];
}


int main()
{
    Array<std::string> strArr(5, std::string("hello"));
    strArr.Print();
    Access1(strArr, 3) = std::move("world");
    // 不报错，但是不会改变值
    Access2(strArr, 1) = std::move("aaaaa");
    Access3(strArr, 2) = std::move("hhhhh");
    strArr.Print();

    return 0;
}
