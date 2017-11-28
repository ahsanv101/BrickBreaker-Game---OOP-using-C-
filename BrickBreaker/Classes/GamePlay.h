#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Bat.h"
#include "Ball.h"
#include "Board.h"
#include "LTexture.h"
#include "Statics.h"
#include "Board.h"
#include "Object.h"
#include "ScreenManager.h"

#include <typeinfo>



class GamePlay : public ScreenManager
{
    public:

        //ScreenManager Implementation
        GamePlay();
        GamePlay(SDL_Renderer* gRenderer);
        void show();
        void click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** selfPointer);
        ~GamePlay();

        void CreateLevel();


    private:
        SDL_Renderer* renderer;
        bool loadMedia();
        LTexture backgroundSprite, batBallSpriteSheet;
        bool shoot;

        Board* board;
        Bat* bat;
        Ball* ball;

        SDL_Rect side1;
        SDL_Rect side2;
        SDL_Rect side3;

        float x, y, width, height;

        //collision detection functions
        bool detectCollisionBetween(Bat*, Ball*);
        CollisionType detectCollisionBetween(const SDL_Rect& wall, Ball*);
        CollisionType detectCollisionBetween(Brick*, Ball*);
        bool isBallAlive(Ball*);

};

#endif // GAMEPLAY_H
