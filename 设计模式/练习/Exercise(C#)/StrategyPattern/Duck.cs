/* 鸭子类 */
namespace StrategyPatternApplication
{
    public class Duck
    {
        // 构造函数
        public Duck()
        {
            this.shoutBehavior = null;
        }

        // 执行叫喊
        public void PerformShoutOut()
        {
            if (this.shoutBehavior != null)
                this.shoutBehavior.ShoutOut();
        }

        // 修改叫声行为对象
        public void SetShoutObject(ShoutBehavior shoutBehavior)
        {
            this.shoutBehavior = shoutBehavior;
        }

        // 叫声行为对象
        private ShoutBehavior shoutBehavior;
    }
}