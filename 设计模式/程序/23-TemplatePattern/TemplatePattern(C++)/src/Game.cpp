#include "Game.h"
#include <iostream>

namespace TemplatePatternApp
{
    Game::~Game()
    {

    }

    void Game::ShowPoint(int point) const 
    {
        std::cout << "You Get " << point << std::endl;
    }

    bool Game::Play() const
    {
        // 初始化游戏
        if (this->Initialize() == false)
        {
            std::cout << "Initialize Game Fail\n";
            return false;
        }

        // 进行游戏
        int point = this->PlayGame();

        // 结束游戏
        this->EndGame();

        // 显示分数
        this->ShowPoint(point);

        return true;
    }
}