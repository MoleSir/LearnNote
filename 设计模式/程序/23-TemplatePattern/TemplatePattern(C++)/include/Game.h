#ifndef __GAME_H__
#define __GAME_H__


namespace TemplatePatternApp
{
    /* 游戏基类 */
    class Game
    {
    public:
        virtual ~Game();

    protected:
        // 虚函数，用于子类重写
        virtual bool Initialize() const = 0;
        virtual int PlayGame() const = 0;
        virtual void EndGame() const = 0;

        // 不需要子类重写的流程，这是固定的
        void ShowPoint(int point) const;

    public:
        // 游戏流程，所有的游戏都是固定的
        bool Play() const;
    };
}


#endif