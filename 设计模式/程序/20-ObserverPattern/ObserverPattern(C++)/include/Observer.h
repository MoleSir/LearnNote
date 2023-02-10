#ifndef __OBSERVER_H__
#define __OBSERVER_H__

namespace ObserverPatternApp
{
    /* 观察者基类 */
    class Observer
    {
    public:
        virtual void Update(int newState) const = 0;
    };

    /* 观察者实体类 */
    class BinaryObserver : public Observer
    {
    public:
        virtual void Update(int newState) const override;
    };

    class OctalObserver : public Observer
    {
    public:
        virtual void Update(int newState) const override;
    };

    class HexaObserver : public Observer
    {
    public:
        virtual void Update(int newState) const override;
    };
}

#endif