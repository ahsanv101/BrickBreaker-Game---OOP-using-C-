#include "NormalFire.h"

//
//NormalFire::NormalFire(LTexture* image, float x, float y)
//{
//    spriteSheetTexture = image;
//
//
//    //Frame 0
//    spriteClips[ 0 ].x =   0;
//    spriteClips[ 0 ].y =   0;
//    spriteClips[ 0 ].w = 24;
//    spriteClips[ 0 ].h = 24;
//
//
////    //Frame 1
////    spriteClips[ 1 ].x = 128;
////    spriteClips[ 1 ].y =   0;
////    spriteClips[ 1 ].w = 128;
////    spriteClips[ 1 ].h = 96;
////
////    //Frame 2
////    spriteClips[ 2 ].x = 256;
////    spriteClips[ 2 ].y = 0;
////    spriteClips[ 2 ].w = 128;
////    spriteClips[ 2 ].h = 96;
//
//    this->x = x;
//    this->y = y;
//
//    this->width = spriteClips[ 0 ].w;
//    this->height = spriteClips[ 0 ].h;
//
//    friction = 0.50f;
//    speedx = 0;
//    speedy = 0;
//    alive  = true;
//}


NormalFire::~NormalFire()
{
    spriteSheetTexture = NULL;
}

void NormalFire::SetAlive(bool alive)
{
    this->alive = alive;
}

bool NormalFire::GetAlive()
{
    return alive;
}

void NormalFire::Move(int direction)
{
//
//    if(direction==UP)
//    {
//        speedy = -5;
//        y+=speedy;
//    }
//
//    if(direction==DOWN)
//    {
//        speedy = 5;
//        y+=speedy;
//    }

}

void NormalFire::Move()
{

     //speedy = speedy * friction;

        speedy = 5;
        y-=speedy;

        //speedx = speedx * friction;
        x = x + speedx;
//
//
//            y = y + speedy;
}

void NormalFire::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
