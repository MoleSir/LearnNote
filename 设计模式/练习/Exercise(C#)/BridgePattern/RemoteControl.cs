/* 遥控器基类 */
namespace BridgePatternApplication
{
    public abstract class RemoteControl
    {
        // 构造函数
        public RemoteControl(TV tv)
        {
            this.tv = tv;
        }

        // 三个抽象函数
        // 开电视
        public abstract void On();

        // 关电视
        public abstract void Off();

        // 切换频道
        public abstract void TuneChannel();

        // 遥控器控制电视对象
        protected TV tv;
    }
}