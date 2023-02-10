/* C++ 实现单例模式 */
#include <iostream>
#include <string>
#include <mutex>
#include <atomic>


/* 懒汉式-线程不安全 */
class SingleObject
{
// 设置构造函数为私有
private:
    SingleObject() {}
public:
    // 负责释放内存
    ~SingleObject() { delete SingleObject::singleHandler; }

public:
    // 一个全局静态指针
    static SingleObject* singleHandler;
    // 一个获取函数对象的静态函数
    static SingleObject* GetSingleObject()
    {
        // 如果还没创建
        if (singleHandler == nullptr)
        {
            // 创建一个
            std::cout << "Create a single object!" << std::endl;
            try
            {
                singleHandler = new SingleObject();
                if (singleHandler == nullptr) throw std::string("No more memory");
            }
            catch(std::string errMessage)
            {
                std::cout << errMessage << std::endl;
            }
        }
        else
        {
            // 已经创建过
            std::cout << "There is already a single object!" << std::endl;
        }
        return singleHandler;
    }
};

// 初始化指针为空
SingleObject* SingleObject::singleHandler = nullptr;


/* 懒汉式-线程安全 */
class SingleObject2
{
private:
    SingleObject2() {}
    static SingleObject2* singleHandler;
    static std::mutex singleMutex;
public:
    ~SingleObject2() { delete SingleObject2::singleHandler; }
    static SingleObject2* GetSingleObject() 
    {
        std::unique_lock<std::mutex> locker(SingleObject2::singleMutex);
        if (SingleObject2::singleHandler == nullptr)
        {
            try
            {
                SingleObject2::singleHandler = new SingleObject2();
            }
            catch (std::bad_alloc e)
            {
                std::cout << e.what() << std::endl;
                SingleObject2::singleHandler = nullptr;
            }  
        }
        else
        {
            std::cout << "already have a SingtObject2!\n";
        }
        return SingleObject2::singleHandler;
    }
};

SingleObject2* SingleObject2::singleHandler = nullptr;
std::mutex SingleObject2::singleMutex;


/* 双重校验锁-线程安全 */
class SingleObject3
{
private:
    SingleObject3() {}
    static std::atomic<SingleObject3*> singleHandler;
    static std::mutex singleMutex;
public:
    ~SingleObject3() { delete SingleObject3::singleHandler; }
    static SingleObject3* GetSingleObject() 
    {
        if (SingleObject3::singleHandler == nullptr)
        {
            std::unique_lock<std::mutex> locker(SingleObject3::singleMutex);
            try
            {
                SingleObject3::singleHandler = new SingleObject3();
            }
            catch (std::bad_alloc e)
            {
                std::cout << e.what() << std::endl;
                SingleObject3::singleHandler = nullptr;
            }  
        }
        else
        {
            std::cout << "already have a SingtObject3!\n";
        }
        return SingleObject3::singleHandler;
    }
};

std::atomic<SingleObject3*> SingleObject3::singleHandler(nullptr);
std::mutex SingleObject3::singleMutex;


int main()
{
    SingleObject* singleObj1 = SingleObject::GetSingleObject();
    SingleObject* singleObj2 = SingleObject::GetSingleObject();

    SingleObject2* singleObj21 = SingleObject2::GetSingleObject();
    SingleObject2* singleObj22 = SingleObject2::GetSingleObject();

    SingleObject3* singleObj31 = SingleObject3::GetSingleObject();
    SingleObject3* singleObj32 = SingleObject3::GetSingleObject();

    return 0;
}