/* 命令子类实现：关灯 */
namespace CommandPatternApplication
{
    public class LightOffCommand : Command
    {
        // 构造函数
        public LightOffCommand(Light light)
        {
            this.light = light;
        }

        // 执行命令
        public void Execute()
        {
            light.Off();
        }

        // 一盏灯
        private Light light;
    }
}