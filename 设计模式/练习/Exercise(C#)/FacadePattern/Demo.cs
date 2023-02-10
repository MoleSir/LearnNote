/*
* 观看电影需要操作很多电器，使用外观模式实现一键看电影功能。
*/
namespace FacadePatternApplication
{
    class Program
    {
        static void Main(string [] args)
        {
            Facade facade = new Facade();
            facade.WatchMovie("Iron Man");
        }
    }
}