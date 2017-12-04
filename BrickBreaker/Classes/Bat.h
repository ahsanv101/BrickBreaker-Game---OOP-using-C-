#ifndef BAT_H
#define BAT_H
#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include"Board.h"
#include"Statics.h"
using namespace std;


class Bat : public Object
{
    public:
        bool alive;
        float speedx;
        float speedy;
        int bigwidth;
        int smallwidth;
        int normalwidth;
        int height;
        float friction; //lower speed means more friction

        enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        SDL_Rect spriteClips2[ FLYING_FRAMES ];
        SDL_Rect spriteClips3[ FLYING_FRAMES ];
        //SDL_Rect spriteClips2[ 0 ];

        LTexture* spriteSheetTexture;




        virtual ~Bat();
        void SetAlive(bool);
        bool GetAlive();
        virtual void Move(int direction);
        float GetReflection(float hitx);
        bool Collides(Board* other);
        //virtual void Move(int direction, SDL_Rect& side);
        virtual void Move();
        virtual void Render(SDL_Renderer* gRenderer);
        static Bat* GetInstance();

        void SetValue(LTexture* image, float x, float y);
    private:
        static Bat* instance;
        Bat(){}
};


#endif // BAT_H
