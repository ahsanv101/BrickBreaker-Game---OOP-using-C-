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
using namespace std;
enum MMOTION {RRIGHT, LLEFT, UUP, DDOWN};

class NormalBall :public Ball
{
    public:
        bool alive;
        float x;
        float y;
        float dirx;
        float diry;
        float speedx;
        float speedy;
        int width;
        int height;
        float friction; //lower speed means more friction
        int BALL_SPEED = 7;
        enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;
        void SetDirection(float dirx, float diry);

    public:
        NormalBall(LTexture* image, float x, float y);
        NormalBall();
        virtual ~NormalBall();
        void SetAlive(bool);
        bool GetAlive();
       // virtual void Move(int direction);
        virtual void Move(float xx, float yy);

        bool Collides(Board* other);
        bool Collide2(Bat* other);
        bool Collides3(Board* other);
        bool Collidesleft(Board* other);
        bool Collidesright(Board* other);
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};




#endif // BALL_H
