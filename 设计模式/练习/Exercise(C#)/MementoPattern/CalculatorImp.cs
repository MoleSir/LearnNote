/* 计算器实现 */
namespace MementoPatternApplication
{
    public class CalculatorImp : Calculator
    {
        // 构造函数
        public CalculatorImp(int firstNumer, int secondNumber)
        {
            this.firstNumer = firstNumer;
            this.secondNumber = secondNumber;
        }

        // 创建当前的备忘录，保存状态
        public PreviousCalculationToOriginator BackupLastCalculation()
        {
            // 以当前状态创建一个备忘录
            return new PreviousCalculationImp(this.firstNumer, this.secondNumber);
        }  

        // 从一个备忘录中恢复数据
        public void RestorePreviousCalculation(PreviousCalculationToOriginator memento)
        {
            // 从备忘录中获取操作数
            this.firstNumer = memento.GetFirstNumber();
            this.secondNumber = memento.GetSecondNumber();
        }

        // 获取计算结果
        public int GetCalculationResult()
        {
            return this.firstNumer + this.secondNumber;
        }

        // 设置计算参数
        public void SetFirstNumber(int firstNumer)
        {
            this.firstNumer = firstNumer; 
        }
        public void SetSecondNumber(int secondNumber)
        {
            this.secondNumber = secondNumber;
        }

        // 私有操作数
        private int firstNumer;
        private int secondNumber;
    }
}