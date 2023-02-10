/* 看电影外观类，将三个步骤合并，简化 */
namespace FacadePatternApplication
{
    public class Facade
    {
        // 构造函数
        public Facade()
        {
            this.subSystem = new SubSystem();
        }

        // 合并三个函数
        public void WatchMovie(string CD)
        {
            this.subSystem.TurnOnTV();
            this.subSystem.SetCD(CD);
            this.subSystem.StartWatching();
        }

        // 复合一个 SubSystem
        private SubSystem subSystem;
    }
}