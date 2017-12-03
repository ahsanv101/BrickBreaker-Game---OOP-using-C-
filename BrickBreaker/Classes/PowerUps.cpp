#include "PowerUps.h"
#include "string"
#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <sstream>
PowerUps::PowerUps(LTexture* image, int x, int y)
{
    this->objectType = ObjectPowerType;
    random  = rand() % 12 + 1;
    spriteSheetTexture = image;


    spriteClips1[ 0 ].x =   2;
    spriteClips1[ 0 ].y =   2;
    spriteClips1[ 0 ].w = 36;
    spriteClips1[ 0 ].h = 36;

    spriteClips2[ 0 ].x =   42;
    spriteClips2[ 0 ].y =   2;
    spriteClips2[ 0 ].w = 36;
    spriteClips2[ 0 ].h = 36;

    spriteClips3[ 0 ].x =   82;
    spriteClips3[ 0 ].y =  2;
    spriteClips3[ 0 ].w = 36;
    spriteClips3[ 0 ].h = 36;

    spriteClips4[ 0 ].x =  122;
    spriteClips4[ 0 ].y =  2;
    spriteClips4[ 0 ].w = 36;
    spriteClips4[ 0 ].h = 36;

    spriteClips5[ 0 ].x =   162;
    spriteClips5[ 0 ].y =   2;
    spriteClips5[ 0 ].w = 36;
    spriteClips5[ 0 ].h = 36;

    spriteClips6[ 0 ].x =   202;
    spriteClips6[ 0 ].y =   2;
    spriteClips6[ 0 ].w = 36;
    spriteClips6[ 0 ].h = 36;

    spriteClips7[ 0 ].x =   2;
    spriteClips7[ 0 ].y =   42;
    spriteClips7[ 0 ].w = 36;
    spriteClips7[ 0 ].h = 36;

    spriteClips8[ 0 ].x =   42;
    spriteClips8[ 0 ].y =   42;
    spriteClips8[ 0 ].w = 36;
    spriteClips8[ 0 ].h = 36;

    spriteClips9[ 0 ].x =   82;
    spriteClips9[ 0 ].y =   42;
    spriteClips9[ 0 ].w = 36;
    spriteClips9[ 0 ].h = 36;

    spriteClips10[ 0 ].x =   2;
    spriteClips10[ 0 ].y =   82;
    spriteClips10[ 0 ].w = 36;
    spriteClips10[ 0 ].h = 36;

    spriteClips11[ 0 ].x =   42;
    spriteClips11[ 0 ].y =   82;
    spriteClips11[ 0 ].w = 36;
    spriteClips11[ 0 ].h = 36;

    spriteClips12[ 0 ].x =   82;
    spriteClips12[ 0 ].y =   82;
    spriteClips12[ 0 ].w = 36;
    spriteClips12[ 0 ].h = 36;



    this->x = x;
    this->y = y;

    this->width = spriteClips1[ 0 ].w;
    this->height = spriteClips1[ 0 ].h;

    friction = 0.50f;

    alive  = true;
}


PowerUps::~PowerUps()
{
    spriteSheetTexture = NULL;
}




void PowerUps::Move()
{
        speedy = 5;
        y+=speedy;
}

void PowerUps::Render(long int frame, SDL_Renderer* gRenderer)
{

    switch(random)
    {
        case 1 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips1[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 2 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips2[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 3 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips3[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 4  : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips4[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 5 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips5[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 6 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips6[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 7 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips7[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                break;
        case 8 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips8[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 9 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips9[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;

        case 10 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips10[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 11 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips11[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
        case 12 : spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips12[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                 break;
    }
}
