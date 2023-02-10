#include <iostream>
#include <memory>

#define COPY_OPERATION
#define MOVE_OPERATION


class Object
{
public:
    Object(int data): _data(data) { std::cout << "common construction\n"; }

#ifdef COPY_OPERATION
    Object(const Object& that): _data(that._data) { std::cout << "copy construction\n"; }
    Object& operator = (const Object& that) 
    {
        if (&that == this) return *this;
        this->_data = that._data;
        std::cout << "copy assignment\n";
        return *this;
    }
#endif

#ifdef MOVE_OPERATION
    Object(Object&& that): _data(that._data) { std::cout << "move construction\n"; }
    Object& operator = (Object&& that) 
    {
        this->_data = that._data;
        std::cout << "move assignment\n";
        return *this;
    }
#endif

    ~Object() { std::cout << "destruction\n"; }
private:
    int _data;
};

// 返回拷贝
Object RetCopy()
{
    Object obj(12);
    // 操作
    return obj;
}

// 返回 move
Object RetMove()
{
    Object obj(13);
    // 操作
    return std::move(obj);
}

void test()
{
    std::cout << "test copy:\n";
    Object obj1 { RetCopy() };
    std::cout << "test move:\n";
    Object obj2 { RetMove() };
    
    std::cout << "destory:\n";
}

int main()
{
    test();

    return 0;
}