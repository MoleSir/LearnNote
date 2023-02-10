/* 基类，提供 Accept 接口 */
namespace VisitorPatternApplication
{
    public interface Element
    {
        // 使用不同的 Visitor 子类完成不同的工作
        void Accept(Visitor visitor);
    }
}