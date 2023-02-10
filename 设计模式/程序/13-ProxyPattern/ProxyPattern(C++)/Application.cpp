/* C++ 实现代理模式 */
#include <iostream>
#include <string>


namespace ProxyPattern
{
    /* 接口 ***************************************/
    class Image
    {
    public:
        virtual void display() = 0;
    };


    /* 创建实现接口的实体类 ************************/
    class RealImage : public Image
    {
    public:
        RealImage(const std::string& fileName) : _fileName(fileName)
        {}
        virtual void display() override
        {
            std::cout << "Load file: " << this->_fileName << std::endl;
        }
    private:    
        std::string _fileName;    
    };

    class ProxyImage : public Image
    {
    public:
        ProxyImage(const std::string& fileName) : _fileName(fileName), _realImage(nullptr)
        {}
        ~ProxyImage()
        {
            if (this->_realImage != nullptr)
                delete this->_realImage;
        }

        virtual void display() override
        {
            if (this->_realImage == nullptr)
            {
                this->_realImage = new RealImage(this->_fileName);
            }
            this->_realImage->display();
        }
    private:
        std::string _fileName;
        RealImage* _realImage;
    };
}

/* 当被请求时，使用 ProxyImage 来获取 RealImage 类的对象 */
int main(int argc, char* argv[])
{
    using namespace ProxyPattern;

    Image* image = new ProxyImage("test_10mb.jpg");

    // 图像将从磁盘加载
    image->display(); 
    // 图像不需要从磁盘加载
    image->display();

    delete image;

    return 0;  
}