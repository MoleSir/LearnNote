/* 字符串的生成器 */
namespace BuilderPatternApplication
{
    public class StringBuilder : AbstractStringBuilder
    {
        // 构造函数
        public StringBuilder(int capacity): base(capacity) {}
        public StringBuilder(int capacity, char ch): base(capacity, ch) {}

        // 获取字符串对象
        public override string ToString()
        {
            // 根据 datas 创建一个字符串
            return new string(this.datas);
        }
    }
}