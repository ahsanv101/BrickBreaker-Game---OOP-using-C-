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
        int bigwidth;
        int smallwidth;
        int height;
        float friction; //lower speed means more friction

        enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        SDL_Rect spriteClips2[ FLYING_FRAMES ];
        SDL_Rect spriteClips3[ FLYING_FRAMES ];
        //SDL_Rect spriteClips2[ 0 ];

        LTexture* spriteSheetTexture;



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
        virtual void Render(SDL_Renderer* gRenderer);
        void Render2(SDL_Renderer* gRenderer);
        void Render3(SDL_Renderer* gRenderer);
};




#endif // BAT_H
