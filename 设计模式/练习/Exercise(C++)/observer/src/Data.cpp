#include "Data.h"
#include <iostream>


Data::Data(std::initializer_list<double> initList) noexcept
    : _data{initList} {}


bool Data::ModifyData(std::size_t index, double newVal) noexcept
{
    if (index >= this->_data.size()) return false; 
    
    this->_data[index] = newVal;

    this->NotifyObservser();
    return true;
}


void Data::ShowData() const noexcept
{
    using const_iterator = std::vector<double>::const_iterator;
    std::size_t i = 0;
    for (const_iterator iter = this->_data.cbegin(); iter != this->_data.cend(); ++iter)
    {
        std::cout << "No." << i++ << " : " << *iter << std::endl;
    }  
}


const std::vector<double>& Data::GetData() const noexcept
{
    return this->_data;
}