#include "Game.h"
#include "CricketGame.h"
#include "FootballGame.h"
#include <iostream>


int main()
{
    using namespace TemplatePatternApp;

    std::cout << "Welcom to Football Game!\n";
    Game* footballGame = new FootballGame();    
    footballGame->Play();
    delete footballGame;

    std::cout << '\n';

    std::cout << "Welcom to Cricket Game!\n";
    Game* cricketGame = new CricketGame();
    cricketGame->Play();
    delete cricketGame;

    return 0;
}