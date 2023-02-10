/* 抽象基类 */
namespace CompositePatternApplication
{
    public abstract class Component 
    {
        // 构造函数
        public Component(string name)
        {
            this.name = name;
        }

        // 调用接口，从第0层开始
        public void Print()
        {
            this.PrintImp(0);
        }

        // 抽象函数，子类实现
        public abstract void PrintImp(int level);

        // 保存节点信息
        protected string name;
    }
}