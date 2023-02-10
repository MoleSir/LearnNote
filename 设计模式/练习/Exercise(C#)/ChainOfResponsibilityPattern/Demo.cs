namespace ChainOfResponsibilityPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Handler handler1 = new ConcreteHandler1(null);
            Handler handler2 = new ConcreteHandler2(handler1);

            Request request1 = new Request(RequestType.TYPE1, "request1");
            handler2.HandleRequest(request1);

            Request request2 = new Request(RequestType.TYPE2, "request2");
            handler2.HandleRequest(request2);
        }
    }
}