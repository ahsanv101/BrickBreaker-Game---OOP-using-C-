#ifndef BALL_H
#define BALL_H
#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Bat.h"
using namespace std;
//enum MMOTION {RRIGHT, LLEFT, UUP, DDOWN};

class Ball : public Object
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
        bool shouldMove;
        int BALL_SPEED = 7;
//        SDL_Rect spriteClips[ FLYING_FRAMES ];
//        LTexture* spriteSheetTexture;
//        void SetDirection(float dirx, float diry);

//    public:
//        Ball(LTexture* image, float x, float y);
//        Ball();
//        virtual ~Ball();
//       // virtual void Move(int direction);
        virtual void Move(float x, float y) = 0;
        virtual void Render(long int frame, SDL_Renderer* gRenderer) = 0;
        void SetDirection(float dirx, float diry);
        virtual void Move();
};




#endif // BALL_H
