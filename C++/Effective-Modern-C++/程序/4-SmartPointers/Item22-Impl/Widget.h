#ifndef __WIDGET_H__
#define __WIDGET_H__


#include <memory>

class Widget
{
public:
    Widget();
    ~Widget();

    Widget(const Widget& rhs);
    Widget& operator = (const Widget& rhs);

    Widget(Widget&& rhs);
    Widget& operator = (Widget&& rhs);

private:
    struct Impl;
    std::unique_ptr<Widget::Impl> _pImpl;
}; 


#endif