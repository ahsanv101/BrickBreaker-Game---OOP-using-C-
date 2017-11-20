#ifndef BAT_H
#define BAT_H
#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include"Board.h"
using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Bat : public Object
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
        Bat(LTexture* image, float x, float y);
        Bat();
        virtual ~Bat();
        void SetAlive(bool);
        bool GetAlive();
        virtual void Move(int direction);
        float GetReflection(float hitx);
        bool Collides(Board* other);
        //virtual void Move(int direction, SDL_Rect& side);
        virtual void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};




#endif // BAT_H
