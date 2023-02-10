#ifndef __SUBJECT_H__
#define __SUBKECT_H__


#include <memory>
#include <list>
#include <vector>

class Observer;

class Subject
{
    using const_iterator = std::list< std::shared_ptr<Observer> >::const_iterator;
    using itertor = std::list< std::shared_ptr<Observer> >::iterator;
    
public:
    Subject() noexcept;

    virtual ~Subject() = default;

    void AddObserver(Observer* observer) noexcept;

    void RemoveObserver(Observer* observer) noexcept;

    void NotifyObservser() noexcept;

    virtual bool ModifyData(std::size_t index, double newVal) noexcept = 0;

    virtual void ShowData() const noexcept = 0;

    virtual const std::vector<double>& GetData() const noexcept = 0;

protected:
    std::list< std::shared_ptr<Observer> > _observers;
};


#endif