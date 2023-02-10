#include "CricketGame.h"
#include <iostream>


namespace TemplatePatternApp
{
    bool CricketGame::Initialize() const 
    {
        std::cout << "Wait Players...\n";
        std::cout << "Prepare Cricket Ground...\n";
        std::cout << "Get Ball\n...";
        return true;
    }
    int CricketGame::PlayGame() const 
    {
        std::cout << "Playing...\n";
        std::cout << "hithithit\n";
        return 11;
    }
    void CricketGame::EndGame() const 
    {
        std::cout << "Clean Cricket Ground...\n";
    }
}