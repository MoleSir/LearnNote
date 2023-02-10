/* 表达式子类实现，终端表达式，类似叶子节点 */
namespace InterpreterPatternApplication
{
    public class TerminalExpression : Expression
    {
        // 构造函数
        public TerminalExpression(string literal)
        {
            this.literal = literal;
        }

        // 运算接口，检查 context 中是否包含 literal
        public bool Interpret(string context)
        {
            // 将 context 以空格分隔开
            string[] literals = context.Split(' ');
            // 检测其中是否存在 literal
            foreach (string literal in literals)
            {
                if (literal == this.literal)
                    return true;
            }
            return false;
        }

        // 最终值
        private string literal;
    }
}