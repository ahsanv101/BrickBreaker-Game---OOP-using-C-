#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Bat.h"
#include "Ball.h"
#include "Board.h"
#include "LTexture.h"

class GamePlay
{
    public:

        const int SCREEN_WIDTH = 1000;
        const int SCREEN_HEIGHT = 650;
        const int speed = 5;
        Bat* bat;
        Ball* ball;
        Board* board1;
        Board* board2;
        Board* board3;
        GamePlay();
        ~GamePlay();
        void Render(long int& frame, SDL_Renderer* gRenderer);


    private:
};

#endif // GAMEPLAY_H
