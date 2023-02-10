#include "Widget.h"
#include <string.h>
#include <memory>

struct Widget::Impl
{
    std::string _title;
    std::size_t _length;
    std::size_t _width;
};

Widget::Widget() 
    : _pImpl(std::make_unique<Widget::Impl>()) 
{}

Widget::~Widget() = default;

Widget::Widget(const Widget& rhs) : _pImpl(std::make_unique<Widget::Impl>(*(rhs._pImpl)))
{

}

Widget& Widget::operator = (const Widget& rhs)
{
    if (this == &rhs) return *this;
    *(this->_pImpl) = *(rhs._pImpl);
    return *this;
}

Widget::Widget(Widget&& rhs) = default;

Widget& Widget::operator = (Widget&& rhs) = default;


