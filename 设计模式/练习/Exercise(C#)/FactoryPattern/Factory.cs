/* 工厂基类 */
namespace FactoryPattenApplication
{
    public interface Factory
    {
        // 获取产品
        Product CreateProfuct(string message);
    }
}