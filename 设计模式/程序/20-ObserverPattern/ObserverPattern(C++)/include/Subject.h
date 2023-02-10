#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include "Observer.h"
#include <list>

namespace ObserverPatternApp
{
    /* Subject 类，待观察的类 */
    class Subject
    {
    public:
        Subject(int state);
        // 添加观察者
        void AddObserver(Observer* observer);
        // 状态改变
        void SetState(int newState);

    private:
        // 触发所有观察者链表
        void NotifyAllObservers()  const;

        // 状态
        int _state;
        // 观察者链表
        std::list<Observer*> _observers;
    };
}

#endif