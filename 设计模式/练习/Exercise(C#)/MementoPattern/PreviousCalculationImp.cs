/* 计算器备忘录实现类 */
namespace MementoPatternApplication
{
    public class PreviousCalculationImp : PreviousCalculationToOriginator
    {
        // 构造函数，创建一个备忘录
        public PreviousCalculationImp(int firstNumer, int secondNumber)
        {
            this.firstNumer = firstNumer;
            this.secondNumber = secondNumber;
        }

        // 从备忘录中获取备份
        public int GetFirstNumber()
        {
            return this.firstNumer;
        }
        public int GetSecondNumber()
        {
            return this.secondNumber;
        }

        // 私有操作数，保存数据
        private int firstNumer;
        private int secondNumber;
    }
}