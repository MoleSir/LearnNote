/* 处理器的具体实现2 */
using System;

namespace ChainOfResponsibilityPatternApplication
{
    public class ConcreteHandler2 : Handler
    {
        // 构造函数
        public ConcreteHandler2(Handler handler) : base(handler) {}

        // 实现抽象函数
        public override void HandleRequest(Request request)
        {
            // 处理类型1的需求
            if (request.GetRequestType() == RequestType.TYPE2)
            {
                // 可以处理
                Console.WriteLine("{0} is handled by ConcreteHandler2", request.GetRequestName());
                return;
            }

            // 如果不是类型1，交给其他的处理器
            if (this.successor != null)
                this.successor.HandleRequest(request);
            else
                // 已经到链表尾部了
                Console.WriteLine("Can't handle {0}", request.GetRequestName());
        }
    }
}