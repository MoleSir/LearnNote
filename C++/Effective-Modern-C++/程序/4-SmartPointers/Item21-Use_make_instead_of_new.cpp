#include <iostream>
#include <memory>

class Object
{
public:
    static void* operator new (std::size_t size) 
    {
        std::cout << "self operator new\n";
        return ::operator new (size);
    }
    static void operator delete (void* rawMemory, std::size_t size)
    {
        std::cout << "self operator delete\n";
        ::operator delete(rawMemory, size);
    }
};

int main()
{
    Object* pObj = new Object{};
    delete pObj;

    // 使用 new 创建，不指定删除器，调用的还是 Object 自定义的 operator new 、 delete
    std::shared_ptr<Object> sp1(new Object{});

    // 使用 new 创建，指定删除器，delete pObj 调用的是 Object 本身的 delete
    auto deleter = [] (Object* pObj) { 
        std::cout << "deleter!\n";
        delete pObj;
    };
    std::shared_ptr<Object> sp2(new Object(), deleter);

    // 使用 make，没有调用 Object 自定义的 operator new 与 operator delete
    // 因为要创建 对象 + 控制块
    std::shared_ptr<Object> sp3(std::make_shared<Object>());

    return 0;
}