/* 饮料的实现类，焦糖咖啡 */
namespace DecoratorPatternApplication
{
    public class DarkRoast : Beverage
    {
        // 实现抽象接口
        public override double Cost()
        {
            return 0.7;
        }
    }
}