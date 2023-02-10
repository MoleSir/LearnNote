/*
* 鸭子（Duck）和火鸡（Turkey）拥有不同的叫声，
* Duck 的叫声调用 Quack() 方法，
* 而 Turkey 调用 Gobble() 方法。
* 要求将 Turkey 的 Gobble() 方法适配成 Duck 的 Quack() 方法，
* 从而让火鸡冒充鸭子！
*/
namespace AdapterPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            // 一个鸭群
            Duck[] ducks = new Duck[5];
            for (int i = 0; i < 4; ++i)
                ducks[i] = new DomesticDuck();
            // 混进一只野生火鸡
            ducks[4] = new TurkeyAdapter(new WildTurkey());

            for (int i = 0; i < 5; ++i)
                ducks[i].Quack();
        }
    }
}

