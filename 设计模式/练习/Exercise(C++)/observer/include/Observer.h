#ifndef __OBSERVER_H__
#define __OBSERVER_H__


#include <memory>

class Subject;

class Observer
{
public:
    Observer(Subject* subject) noexcept;

    virtual ~Observer() noexcept = default;

    virtual void Update() noexcept = 0;

protected:
    std::shared_ptr<Subject> _subject;
};


#endif