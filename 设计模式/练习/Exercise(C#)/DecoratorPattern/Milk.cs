/* 饮料适配器实现类，牛奶 */
namespace DecoratorPatternApplication
{
    public class Mike : CondimentDecorator
    {
        // 构造函数
        public Mike(Beverage beverage) : base(beverage) {}

        // 重写接口
        public override double Cost()
        {
            // 使用复合而来的饮料，并且这个饮料是动态绑定
            return 1.0 + this.beverage.Cost();
        }
    }
}