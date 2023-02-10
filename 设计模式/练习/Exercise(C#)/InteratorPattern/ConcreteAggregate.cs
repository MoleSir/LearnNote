/* 某个数据结构的具体实现 */
namespace InteratorPatternApplication
{
    public  class ConcreteAggregate<Ty> : Aggregate<Ty>
    {
        // 构造函数 
        public ConcreteAggregate(int size, Ty value)
        {
            this.data = new Ty[size];
            for (int i = 0; i < size; ++i)
                this.data[i] = value;
        }

        // 获取迭代器
        public Iterator<Ty> CreateIterator()
        {
            return new ConcreteIterator<Ty>(this.data);
        }

        // 有一个数组保存数据
        private Ty[] data;
    }
}