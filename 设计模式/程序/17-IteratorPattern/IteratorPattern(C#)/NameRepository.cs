using System;

namespace IteratorPattern
{
    /* 容器 */
    public class NameRepository : Container
    {
        /* 类内的迭代器定义 */
        private class NameIterator : Iterator
        {
            public NameIterator(string[] names)
            {
                this.names = names;
                this.index = 0;
            }
            // 实现两个迭代器重载函数
            public bool HasNext()
            {
                if (index < this.names.Length)
                    return true;
                return false;
            }
            public object Next()
            {
                if (this.HasNext() == true)
                    return this.names[index++];
                return null;
            }

            private string[] names;
            private int index;
        }

        // 构造函数，输入一个数组
        public NameRepository(string[] names)
        {
            this.names = names;
        }

        // 实现虚函数
        public Iterator GetIterator()
        {
            return new NameIterator(this.names);
        }

        // 数组
        private string[] names;
    }   

}