/* 计算器接口 */
namespace MementoPatternApplication
{
    public interface Calculator
    {
        // 创建当前的备忘录，保存状态
        PreviousCalculationToOriginator BackupLastCalculation();   

        // 从一个备忘录中恢复数据
        void RestorePreviousCalculation(PreviousCalculationToOriginator memento);

        // 获取计算结果
        int GetCalculationResult();

        // 设置计算参数
        void SetFirstNumber(int firstNumer);

        void SetSecondNumber(int secondNumber);
    }
}