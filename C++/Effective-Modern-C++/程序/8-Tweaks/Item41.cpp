#include "Object.h"
#include <iostream>
#include <string>
#include <vector>


namespace function_overload
{
    class Widget
    {
    public:
        Widget(Object&& object) : _object(std::move(object)) 
        { std::cout << "Widget move construction\n"; }
        Widget(const Object& object) : _object(object) 
        { std::cout << "Widget copy construction\n"; }

        void AddName(std::string&& name)
        { 
            std::cout << "move add\n";
            this->_names.push_back(std::move(name)); 
        }
        void AddName(const std::string& name)
        {   
            std::cout << "copy add\n";
            this->_names.push_back(name); 
        }

    private:
        Object _object;
        std::vector<std::string> _names;
    };
}

namespace general_reference
{
    class Widget
    {
    public:
        template < typename T, 
                   typename = typename std::enable_if< !std::is_same<Widget, typename std::decay<T>::type
                >::value
            >::type
        >
        Widget(T&& object) : _object(std::forward<T>(object)) {}

        template <typename T,
                  typename = typename std::enable_if< std::is_same<std::string, typename std::decay<T>::type
                >:: value
            >::type
        >
        void AddName(T&& name)
        {   
            this->_names.push_back(std::forward<T>(name)); 
        }


    private:
        Object _object;
        std::vector<std::string> _names;
    };
}

namespace pass_by_value
{
    class Widget
    {
    public:
        Widget(Object object) : _object(std::move(object)) {}
        
        void AddName(std::string name) 
        {
            this->_names.push_back(std::move(name));
        }

    private:
        Object _object;
        std::vector<std::string> _names;
    };
}


int main()
{
    using namespace pass_by_value;
    //using namespace general_reference;
    //using namespace function_overload;
    auto test = []()
    {
        Object obj1(12);
        Widget w1(obj1);
        Widget w2(Object(44));

        std::string name = "YeChen";
        w1.AddName(name);
        w2.AddName(std::string("XuYuting"));
    };

    test();

    return 0;
}