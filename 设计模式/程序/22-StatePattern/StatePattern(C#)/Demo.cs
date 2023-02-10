using System;

namespace StatePatternApp
{
    class Program
    {
        static void Main()
        {
            StateA a = new StateA();
            StateB b = new StateB();
            StateC c = new StateC();

            Subject subject = new Subject(a);
            subject.Operation1("fffff");

            subject.SetState(b);
            subject.Operation2("zzzzz");

            subject.SetState(c);
            subject.Operation3("nnnnn");
        }
    }
}