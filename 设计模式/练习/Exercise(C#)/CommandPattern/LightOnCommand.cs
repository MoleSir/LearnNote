/* 命令子类实现：开灯 */
namespace CommandPatternApplication
{
    public class LightOnCommand : Command
    {
        // 构造函数
        public LightOnCommand(Light light)
        {
            this.light = light;
        }

        // 执行命令
        public void Execute()
        {
            light.On();
        }

        // 一盏灯
        private Light light;
    }
}