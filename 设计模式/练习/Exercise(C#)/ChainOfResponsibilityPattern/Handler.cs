/* 处理类的抽象基类 */
namespace ChainOfResponsibilityPatternApplication
{
    public abstract class Handler
    {
        // 构造函数
        public Handler(Handler successor)
        {
            this.successor = successor;
        }

        // 处理函数
        public abstract void HandleRequest(Request request);

        // 保存下一个处理器，构成链状结构
        protected Handler successor;
    }
}