#ifndef NORMALBALL_H
#define NORMALBALL_H
#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Board.h"
#include "Bat.h"
#include "Ball.h"
#include "Statics.h"
using namespace std;
enum MMOTION {RRIGHT, LLEFT, UUP, DDOWN};

class NormalBall :public Ball
{
    public:
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;
        //void SetDirection(float dirx, float diry);

    public:
        NormalBall(LTexture* image, float x, float y);
        NormalBall();
        virtual ~NormalBall();
        void SetAlive(bool);
        bool GetAlive();
       // virtual void Move(int direction);
        virtual void Move(float x, float y);

//        bool Collides(Board* other);
        bool Collide2(Bat* other);
        virtual void Render(long int frame, SDL_Renderer* gRenderer);

};




#endif // BALL_H
