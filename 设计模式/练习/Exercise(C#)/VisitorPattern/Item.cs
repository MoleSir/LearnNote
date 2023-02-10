/* Element 的具体实现类，物品类 */
namespace VisitorPatternApplication
{
    public class Item : Element
    {
        // 构造函数
        public Item(string name)
        {
            this.name = name;
        }
        
        public string GetName()
        {
            return this.name;
        } 

        // 重写 Accept
        public void Accept(Visitor visitor)
        {
            // 调用访问者的 Visit 方法，传入 this 可以让 visitor 匹配应该调用针对不同类的 Visit 函数
            visitor.Visit(this);
        }

        // 物品的名称
        private string name;
    }
}
