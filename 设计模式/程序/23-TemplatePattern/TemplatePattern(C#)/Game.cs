using System;

namespace TemplatePatternApp 
{
    /* 游戏抽象类 */
    public abstract class Game
    {
        // 抽象函数，由子类重写
        protected abstract bool Initialize();
        protected abstract int PlayGame();
        protected abstract void EndPlay();

        // 稳定的流程函数，不需要子类重写
        protected void ShowPoint(int point)
        {
            Console.WriteLine("You Get {0} Points!", point);
        }

        // 游戏流程，所有游戏都是固定的，此函数是稳定的
        public bool Play()
        {
            // 初始化游戏
            if (this.Initialize() == false)
            {
                Console.WriteLine("Initialize Game Fail!");
                return false;
            }

            // 进行游戏，并且得到分数
            int point = this.PlayGame();

            // 结束游戏
            this.EndPlay();

            // 显示分数
            this.ShowPoint(point);

            return true;
        }

    }
}