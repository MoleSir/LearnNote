/* 产品基类 */
namespace FactoryPattenApplication
{
    public abstract class Product
    {
        // 构造函数
        public Product(string message)
        {
            this.message = message;
        }

        public string GetMessage()
        {
            return this.message;
        }

        public void SetMessage(string message)
        {
            this.message = message;
        }

        // 产品信息
        protected string message;  
    } 
}