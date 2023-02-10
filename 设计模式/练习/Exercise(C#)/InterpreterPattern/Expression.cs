/* 表达式基类 */
namespace InterpreterPatternApplication
{
    public interface Expression
    {
        // 运算接口
        bool Interpret(string context);
    }
}
