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
        float x;
        float y;
        float speedx;
        float speedy;
        int width;
        int height;
        float friction; //lower speed means more friction

        enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;

    public:
        Fire(LTexture* image, float x, float y);
        Fire();
        virtual ~Fire();
        void SetAlive(bool);
        bool GetAlive();
        virtual void Move(int direction);
        virtual void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};






#endif // FIRE_H
