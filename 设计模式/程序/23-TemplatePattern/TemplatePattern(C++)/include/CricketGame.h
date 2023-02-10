#ifndef __CRICKETGAME_H__
#define __CRICKETGAME_H__

#include "Game.h"


namespace TemplatePatternApp
{
    class CricketGame : public Game
    {
    protected:
        virtual bool Initialize() const override;
        virtual int PlayGame() const override;
        virtual void EndGame() const override;
    };
}


#endif