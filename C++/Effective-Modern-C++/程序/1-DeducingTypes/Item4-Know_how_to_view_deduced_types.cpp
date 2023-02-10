#include <iostream>
#include <string>

template <typename T>
class TypeDecl;


template <typename T1, typename T2, std::size_t N>
class ComplexClass
{

};

int main()
{
    ComplexClass<double, std::string, 100> c;
    //TypeDecl<decltype(c)> tInfo;

    std::cout << typeid(c).name() << std::endl;

    return 0;
}