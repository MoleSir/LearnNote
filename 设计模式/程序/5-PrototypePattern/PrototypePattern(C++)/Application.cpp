/* C++ 中实现最简单的原型模式 */
#include <iostream>
#include <string>


namespace PrototypePattern
{
    /* 接口 */
    class Prototype
    {
    public:
        virtual Prototype* clone() = 0;
        virtual const std::string& data() = 0;
    };

    class ConcretePrototype: public Prototype
    {  
    public: 
        ConcretePrototype(const std::string& data): _data(data)
        {}
        // 实现拷贝构造
        ConcretePrototype(const ConcretePrototype& that)
        {
            this->_data = that._data;
        }
        // 重写 clone
        virtual Prototype* clone() override
        {
            return new ConcretePrototype((*this));
        }
        // getter
        virtual const std::string& data() override
        {
            return _data;
        }

    private:
        std::string _data;
    };
}


int main()
{
    using namespace PrototypePattern;
    Prototype* c1 = new ConcretePrototype("YeChen");
    Prototype* c2 = c1->clone();

    std::cout << c1->data() << "  ==  " << c2->data() << std::endl;

    delete c1;
    delete c2;
    return 0;
}