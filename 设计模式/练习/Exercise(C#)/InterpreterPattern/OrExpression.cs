/* 逻辑表达式的子类实现，完成与逻辑 */
namespace InterpreterPatternApplication
{
    public class OrExpression : LogicExpression
    {
        // 构造函数
        public OrExpression(Expression expression1, Expression expression2): 
            base(expression1, expression2) {}

        // 实现与计算
        public override bool Interpret(string context)
        {
            return this.expression1.Interpret(context) || this.expression2.Interpret(context);
        }
    }
}