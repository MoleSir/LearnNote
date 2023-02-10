/* 计算器备忘录基类 */
namespace MementoPatternApplication
{
    public interface PreviousCalculationToOriginator
    {
        // 接口可以获取保存在备忘录中的数字
        int GetFirstNumber();
        int GetSecondNumber();
    }
}