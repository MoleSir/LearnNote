/* 火鸡适配器 */
namespace AdapterPatternApplication
{
    public class TurkeyAdapter : Duck
    {
        // 构造函数
        public TurkeyAdapter(Turkey turkey)
        {
            this.turkey = turkey;
        }

        // 实现鸭子的接口
        public void Quack()
        {
            // 调用火鸡叫声
            this.turkey.Gobble();
        }

        // 符合一只火鸡
        private Turkey turkey;
    }
}