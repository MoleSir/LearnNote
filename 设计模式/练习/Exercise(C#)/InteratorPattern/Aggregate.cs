/* 某个数据结构基类 */
namespace InteratorPatternApplication
{
    public interface Aggregate<Ty>
    {
        Iterator<Ty> CreateIterator();
    }
}