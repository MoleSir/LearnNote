#include "Subject.h"
#include "Observer.h"
#include <memory>
#include <iostream>


Subject::Subject() noexcept
    :_observers{} {}


void Subject::AddObserver(Observer* observer) noexcept
{
    if (observer == nullptr) return;
    this->_observers.emplace_back(observer);
}


void Subject::RemoveObserver(Observer* observer) noexcept
{
    if (observer == nullptr) return;

    for (const_iterator iter = this->_observers.cbegin(); iter != this->_observers.cend(); ++iter)
    {
        if ( (*iter).get() == observer ) this->_observers.erase(iter);
    }

    std::cout << "No this observer!\n";
}


void Subject::NotifyObservser() noexcept
{
    for (itertor iter = this->_observers.begin(); iter != this->_observers.end(); ++iter)
    {
        (*iter)->Update();
    }
}

