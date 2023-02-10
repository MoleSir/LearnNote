/* 饮料的实现类，星巴克首席咖啡 */
namespace DecoratorPatternApplication
{
    public class HouseBlend : Beverage
    {
        // 实现抽象接口
        public override double Cost()
        {
            return 2.0;
        }
    }
}