/* 电视接口 */
namespace BridgePatternApplication
{
    public interface TV
    {
        // 开电视
        void On();

        // 关电视
        void Off();

        // 切换频道
        void TuneChannel();
    }
}