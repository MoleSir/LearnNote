#ifndef __TABLE_OBSERVER_H__
#define __TABLE_OBSERVER_H__


#include "Observer.h"

class Subject;

class TableObserver : public Observer
{
public:
    TableObserver(Subject* subject) noexcept;

    virtual void Update() noexcept override;
};

#endif