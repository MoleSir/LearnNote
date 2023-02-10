#include <iostream>
#include <string>

//================================= 常量对象
void TestConstexprObject()
{
    int n = 10;
    // constexpr cn1 = n; 报错

}

//================================= 常量函数
constexpr int MyPow(int base, int exp)
{
    // std::cout << "mypow\n"; --> 不可以有编译器不能确定的对象
    return exp == 0 ? 1 : MyPow(base, exp - 1);
}

void TestConstexprFunction()
{
    // 传入 constexpr 对象
    constexpr int exp = 5;
    int numbers[MyPow(2, exp)]; // 编译通过，MyPow 在编译期间计算

    // 非 constexpr 对象
    int exp2 = 5;
    // int numbers[MyPow(2, exp2)]; --> 编译报错，数组的长度需要在编译期间可知
    // 如果无法编译器确定，在运行期间计算
    int value = MyPow(2, exp2);
}

//=============================== 常量成员函数
class Point
{
public:
    constexpr Point(int x, int y) noexcept : _x(x), _y(y) {}
    Point(int xy) noexcept : _x(xy), _y(xy) {}

    constexpr int GetX() const noexcept { return this->_x; }
    int GetY() const noexcept { return this->_y; }

    void SetX(int x) noexcept { this->_x = x; }
    void SetY(int y) noexcept { this->_y = y; }

private:
    int _x, _y;
};


void TestConstexprNumberFunction()
{
    constexpr Point p(12, 4);
    int numbers1[p.GetX()]; // 编译通过，p 是编译器已知，GetX 也是编译器可知函数
    int numbers2[p.GetY()]; // 有点怪，编译也通过了

    Point p2(23, 1);
    int numbers3[p2.GetX()]; // 有点怪，编译也通过了，可能是编译优化？
    int numbers4[p2.GetY()]; // 有点怪，编译也通过了

    Point p3(12);
    int numbers5[p3.GetX()]; // 有点怪，编译也通过了，可能是编译优化？
    int numbers6[p3.GetY()]; // 有点怪，编译也通过了，可能是编译优化？
}


int main()
{
    std::cout << "Item15\n";
    TestConstexprObject();
    TestConstexprFunction();
    TestConstexprNumberFunction();
}