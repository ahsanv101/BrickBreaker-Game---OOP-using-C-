#ifndef POWERUPS_H
#define POWERUPS_H

#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"

using namespace std;


class PowerUps : public Object
{
    public:
        bool alive;
        float speedx;
        float speedy;
        float friction; //lower speed means more friction
        int random;
        enum ANIMATION_FRAMES {FLYING_FRAMES = 1};

        SDL_Rect spriteClips1[ FLYING_FRAMES ];
        SDL_Rect spriteClips2[ FLYING_FRAMES ];
        SDL_Rect spriteClips3[ FLYING_FRAMES ];
        SDL_Rect spriteClips4[ FLYING_FRAMES ];
        SDL_Rect spriteClips5[ FLYING_FRAMES ];
        SDL_Rect spriteClips6[ FLYING_FRAMES ];
        SDL_Rect spriteClips7[ FLYING_FRAMES ];
        SDL_Rect spriteClips8[ FLYING_FRAMES ];
        SDL_Rect spriteClips9[ FLYING_FRAMES ];
        SDL_Rect spriteClips10[ FLYING_FRAMES ];
        SDL_Rect spriteClips11[ FLYING_FRAMES ];
        SDL_Rect spriteClips12[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;

    public:
        PowerUps(LTexture* image, int x, int y);
        ~PowerUps();
       // PowerUp();
       // virtual void Move(int direction);
        virtual void Move();
        virtual void Render(long int frame, SDL_Renderer* gRenderer);
};

#endif // POWERUPS_H
