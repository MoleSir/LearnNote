#ifndef __OBJECT_H__
#define __OBJECT_H__


#define COPY_OPERATION
#define MOVE_OPERATION

#include <iostream>

class Object
{
public:
    Object(int data): _data(data) { std::cout << "common construction\n"; }

#ifdef COPY_OPERATION
    Object(const Object& that): _data(that._data) { std::cout << "copy construction\n"; }
    Object& operator = (const Object& that) 
    {
        if (&that == this) return *this;
        this->_data = that._data;
        std::cout << "copy assignment\n";
        return *this;
    }
#endif

#ifdef MOVE_OPERATION
    Object(Object&& that): _data(that._data) { std::cout << "move construction\n"; }
    Object& operator = (Object&& that) 
    {
        this->_data = that._data;
        std::cout << "move assignment\n";
        return *this;
    }
#endif

    ~Object() { std::cout << "destruction\n"; }
private:
    int _data;
};


#endif