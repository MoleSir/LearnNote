/* 字符串构造器，类似一个 vector */
using System;

namespace BuilderPatternApplication
{
    public class AbstractStringBuilder
    {
        // 构造函数
        public AbstractStringBuilder(int capacity)
        {
            this.size = 0;
            this.datas = new char[capacity];
        }
        public AbstractStringBuilder(int capacity, char ch)
        {
            this.size = capacity;
            this.datas = new char[capacity];
            for (int i = 0; i < capacity; i++)
                this.datas[i] = ch;
        }

        // 添加一个字符
        public AbstractStringBuilder Append(char ch)
        {
            // 确保容量充足
            this.EnsureCapacityInternal(this.size + 1);
            // 添加字符
            this.datas[this.size] = ch;
            this.size += 1;
            // Console.WriteLine("Add {0}", ch);
            return this;
        }

        // 确保字符数组容量充足
        private void EnsureCapacityInternal(int minimumCapacity)
        {
            // 检测容量是否存在
            if (minimumCapacity > this.datas.Length)
                this.ExpandCapacity(minimumCapacity);
        }
        
        // 拓展容量
        private void ExpandCapacity(int minimumCapacity)
        {
            // 计算新容量
            int newCapacity = this.datas.Length * 2 + 2;
            if (newCapacity < minimumCapacity)
                newCapacity = minimumCapacity;
            
            // 申请新的数组，将原数据拷贝
            char[] newDatas = new char[newCapacity];
            for (int i = 0; i < this.size; ++i)
                newDatas[i] = this.datas[i];
            
            // 更新数组
            this.datas = newDatas;
        }

        // 字符数组
        protected char[] datas;
        // 当前字符串的长度
        protected int size;
    }
}