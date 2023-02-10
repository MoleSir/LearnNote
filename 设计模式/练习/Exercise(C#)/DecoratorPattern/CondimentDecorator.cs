/* 饮料装饰器抽象类 */
namespace DecoratorPatternApplication
{
    public abstract class CondimentDecorator : Beverage
    {
        // 构造函数
        public CondimentDecorator(Beverage beverage)
        {
            this.beverage = beverage;
        }
        
        // 继承基类，复合基类
        protected Beverage beverage;
    }
}