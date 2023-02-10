#include <iostream>

template <typename T>
class TypeDecl;

class Object
{
public:
    Object(int data): _data(data) { std::cout << "common construction\n"; }
    Object(const Object& that): _data(that._data) { std::cout << "copy construction\n"; }
    Object(Object&& that): _data(that._data) { std::cout << "move construction\n"; }
    Object& operator = (const Object& that) 
    {
        if (&that == this) return *this;
        this->_data = that._data;
        std::cout << "copy assignment\n";
        return *this;
    }
    Object& operator = (Object&& that) 
    {
        this->_data = that._data;
        std::cout << "move assignment\n";
        return *this;
    }
    ~Object() { std::cout << "destruction\n"; }
private:
    int _data;
};


namespace TestConstruction
{
    // 万能引用
    void test1(const Object& obj)
    {
        //TypeDecl<decltype(obj)> TD1;
        //TypeDecl<decltype(std::move(obj))> TD2;
        Object obj1(obj);
        Object obj2(std::move(obj));
    }

    // 左值引用
    void test2(Object& obj)
    {
        Object obj1(obj);
        Object obj2(std::move(obj));
    }

    // 右值引用
    void test3(Object&& obj)
    {
        Object obj1(obj);
        Object obj2(std::move(obj));
    }

    void test()
    {
        Object obj(12);
            // common construction

        std::cout << "test1:\n";
        test1(obj);
        test1(std::move(obj));
            // test1:
            // copy construction
            // copy construction
            // copy construction
            // copy construction

        std::cout << "test2:\n";
        test2(obj);
            // test2:
            // copy construction
            // move construction

        std::cout << "test3:\n";
        test3(std::move(obj)); 
            // test3:
            // copy construction
            // move construction
    }
}


namespace TestArgPass
{
    void FuncPassByValue(Object obj)
    {
        // 形参：Object obj = 实参
        Object o {obj};
    }

    void FuncPassByLeftRef(Object& obj)
    {
        // 形参：Object& obj = 实参
        // 引用只是别名
        Object o{obj};
    }

    void test()
    {
        Object obj(12); // common construction
        FuncPassByLeftRef(obj); // 两次 copy construction
        FuncPassByValue(obj);  // 一次 copy construction
    }
}


namespace TestReturnValue
{
    Object* pObj2 = new Object(124);
    Object* pObj3 = new Object(1243);


    // 关闭返回值优化的情况下，return 类型如果是 Object，那么会创建一个临时对象，这个对象的类型跟 return 后一致
    Object FuncRetValue()
    {
        Object* pObj1 = new Object(12); // 创建对象
        // 返回 return 后的对象的本身
        return *pObj1;                  // 返回 Object 对象，拷贝一个临时对象
    }

    Object& FuncRetLeftRef()
    {
        // 返回对象的引用
        return *pObj2;
    }

    // 这个两个函数长得像，如果开启了返回值优化，结果是一样的
    // 但如果没有，返回类型是 Object&& 的话，不会多创建一个临时对象
    Object&& FuncRetRightRef()
    {   
        return std::move(*pObj3);
    } 
    // 而这个函数由于返回值是一个对象 Object 那么会使用 std::move(*pObj3) 通过移动语义先创建一个临时对象
    // 再用这个临时对象去给外面的变量构造，最后临时对象析构~
    Object FuncRetTempObj()
    {
        return std::move(*pObj3);
    }

    void test()
    {
        std::cout << "1:\n";
        Object obj1 {FuncRetValue()};
        std::cout << "2:\n";
        Object obj2 {FuncRetLeftRef()};
        std::cout << "3:\n";
        Object obj3 {FuncRetRightRef()};
        std::cout << "4:\n";
        Object obj4 {FuncRetTempObj()};

        std::cout << "free!:\n";
        //delete pObj1;
        //delete pObj2;
        //delete pObj3;
    }
}


int main()
{   
    // TestArgPass::test();
    TestReturnValue::test();
    return 0;
}