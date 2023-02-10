#include "FootballGame.h"
#include <iostream>

namespace TemplatePatternApp
{
        bool FootballGame::Initialize() const 
        {
            std::cout << "Wait Players...\n";
            std::cout << "Prepare Football Ground...\n";
            return true;
        }
        int FootballGame::PlayGame() const 
        {
            std::cout << "Playing...\n";
            std::cout << "titititti\n";
            return 5;
        }
        void FootballGame::EndGame() const 
        {
            std::cout << "Players Take Shower...\n";
            std::cout << "Clean Football Ground...\n";
        }
}