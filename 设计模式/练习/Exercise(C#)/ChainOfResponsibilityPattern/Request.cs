/* 需求类 */
namespace ChainOfResponsibilityPatternApplication
{
    public class Request
    {
        // 构造函数
        public Request(RequestType type, string name)
        {
            this.requestType = type;
            this.requestName = name;
        }

        public string GetRequestName()
        {
            return this.requestName;
        }

        public RequestType GetRequestType()
        {
            return this.requestType;
        }

        // 需求的种类
        private RequestType requestType;
        // 需求名称
        private string requestName;
    }
}