#include "Subject.h"
#include <list>


namespace ObserverPatternApp
{   
    Subject::Subject(int state): _state(state)
    {}

    void Subject::AddObserver(Observer* observer)
    {
        this->_observers.push_back(observer);
    }

    void Subject::SetState(int newState)
    {
        this->_state = newState;
        this->NotifyAllObservers();
    }

    void Subject::NotifyAllObservers()  const 
    {
        for (Observer* observer : this->_observers)
            observer->Update(this->_state);
    }
}
