#ifndef FireBall_H
#define FireBall_H
#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Board.h"
#include "Bat.h"
#include "Ball.h"
using namespace std;


class FireBall :public Ball
{
    public:
        enum ANIMATION_FRAMES {FLYING_FRAMES = 3};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;
        //void SetDirection(float dirx, float diry);

    public:
        FireBall(LTexture* image, float x, float y);
        FireBall();
        virtual ~FireBall();
        void SetAlive(bool);
        bool GetAlive();
       // virtual void Move(int direction);
        virtual void Move(float xx, float yy);

        bool Collides(Board* other);
        bool Collide2(Bat* other);
        bool Collides3(Board* other);
        bool Collidesleft(Board* other);
        bool Collidesright(Board* other);
        virtual void Render(long int frame,SDL_Renderer* gRenderer);

};




#endif // BALL_H

