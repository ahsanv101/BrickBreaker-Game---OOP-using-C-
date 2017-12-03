#ifndef FIRE_H
#define FIRE_H
#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

using namespace std;


class Fire :public Object
{
    public:
        bool alive;
        float speedx;
        float speedy;

//
//        enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
//        SDL_Rect spriteClips[ FLYING_FRAMES ];
//        LTexture* spriteSheetTexture;

    public:


//        void SetAlive(bool);
//        bool GetAlive();
       // virtual void Move(int direction) = 0;
        virtual void Move()=0;
        virtual void Render(long int frame, SDL_Renderer* gRenderer) = 0;
};






#endif // FIRE_H
