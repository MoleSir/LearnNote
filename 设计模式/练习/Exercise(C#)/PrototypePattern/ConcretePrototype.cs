/* 原型类子类 */
namespace PrototypePatternApplication
{
    public class ConcretePrototype : Prototype
    {
        // 构造函数
        public ConcretePrototype(string strFiled, int intFiled, double floatFiled)
        {
            this.strFiled = strFiled;
            this.intFiled = intFiled;
            this.floatFiled = floatFiled;
        }

        // 重写克隆函数
        public Prototype Clone()
        {
            return new ConcretePrototype(this.strFiled, this.intFiled, this.floatFiled);
        }

        // 输出
        public override string ToString()
        {
            return string.Format("{0}, {1}, {2}", this.strFiled, this.intFiled, this.floatFiled);
        }

        // 私有变量
        private string strFiled;
        private int intFiled;
        private double floatFiled;
    }
}