/* 迭代器基类 */
namespace InteratorPatternApplication
{
    public interface Iterator<Ty>
    {
        // 获取值，并指向下一个值
        Ty Next();

        // 判断是都有下一个
        bool HasNext();
    }
}