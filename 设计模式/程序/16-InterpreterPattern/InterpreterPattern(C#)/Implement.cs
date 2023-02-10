using System;

namespace InterpreterPattern
{
    /* 实现类 */
    public class TerminalExpression : Expression
    {
        public TerminalExpression(string data)
        {
            this.data = data;
        }
        public bool Interpret(string context)
        {
            if (context.Contains(this.data))
                return true;
            return false;
        }

        private string data;
    }

    public class OrExpression : Expression
    {
        public OrExpression(Expression expression1, Expression expression2)
        {
            this.expression1 = expression1;
            this.expression2 = expression2;
        }
        public bool Interpret(string context)
        {
            return this.expression1.Interpret(context) || this.expression2.Interpret(context);
        }

        private Expression expression1;
        private Expression expression2;
    }

    public class AndExpression : Expression
    {
        public AndExpression(Expression expression1, Expression expression2)
        {
            this.expression1 = expression1;
            this.expression2 = expression2;
        }
        public bool Interpret(string context)
        {
            return this.expression1.Interpret(context) && this.expression2.Interpret(context);
        }

        private Expression expression1;
        private Expression expression2;
    }
}