using System;

namespace StatePatternApp
{
    class Subject
    {
        public Subject(State state)
        {
            this.state = state;
        }
        public void SetState(State state)
        {
            this.state = state;
        }

        public void Operation1(string message)
        {
            this.state.DoOperation1(message);
        }
        public void Operation2(string message)
        {
            this.state.DoOperation2(message);
        }
        public void Operation3(string message)
        {
            this.state.DoOperation3(message);
        }

        private State state;
    }
}