#ifndef __FOOTBALLGAME_H__
#define __FOOTBALLGAME_H__

#include "Game.h"


namespace TemplatePatternApp
{
    class FootballGame : public Game
    {
    protected:
        virtual bool Initialize() const override;
        virtual int PlayGame() const override;
        virtual void EndGame() const override;
    };
}


#endif