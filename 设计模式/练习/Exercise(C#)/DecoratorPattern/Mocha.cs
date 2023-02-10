/* 饮料适配器实现类，摩卡 */
namespace DecoratorPatternApplication
{
    public class Mocha : CondimentDecorator
    {
        // 构造函数
        public Mocha(Beverage beverage) : base(beverage) {}

        // 重写接口
        public override double Cost()
        {
            // 使用复合而来的饮料，并且这个饮料是动态绑定
            return 1.2 + this.beverage.Cost();
        }
    }
}