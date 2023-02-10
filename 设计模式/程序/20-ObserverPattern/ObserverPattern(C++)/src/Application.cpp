#include "Observer.h"
#include "Subject.h"
#include <iostream>

int main()
{
    using namespace ObserverPatternApp;

    Subject subject(0);

    BinaryObserver* b = new BinaryObserver();
    OctalObserver* o = new OctalObserver();
    HexaObserver* h = new HexaObserver();

    subject.AddObserver(b);
    subject.AddObserver(o);
    subject.AddObserver(h);

    std::cout << "First state change: 15\n";
    subject.SetState(15);
    std::cout << "Second state change: 10\n";
    subject.SetState(10);

    delete b;
    delete o;
    delete h;

    return 0;
}