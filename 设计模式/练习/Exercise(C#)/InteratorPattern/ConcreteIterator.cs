/* 迭代器实现 */
namespace InteratorPatternApplication
{
    public class ConcreteIterator<Ty> : Iterator<Ty>
    {
        // 构造函数
        public ConcreteIterator(Ty[] data)
        {
            this.data = data;
            this.position = 0;
        }

        // 获取值，并指向下一个值
        public Ty Next()
        {
            return this.data[position++];
        }

        // 判断是都有下一个
        public bool HasNext()
        {
            return this.position < this.data.Length;
        }

        // 保存要迭代的数据
        private Ty[] data;
        // 指向数组的位置
        private int position;
    }
}