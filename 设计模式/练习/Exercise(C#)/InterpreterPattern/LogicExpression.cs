/* 表达式子类实现，逻辑表达式，类似树节点 */
namespace InterpreterPatternApplication
{
    public abstract class LogicExpression : Expression
    {
        // 构造函数 
        public LogicExpression(Expression expression1, Expression expression2)
        {
            this.expression1 = expression1;
            this.expression2 = expression2;
        }

        // 还不能确定运算函数的实现，留给子类
        public abstract bool Interpret(string context);

        // 包含左右两个表达式
        protected Expression expression1;
        protected Expression expression2;
    }
}