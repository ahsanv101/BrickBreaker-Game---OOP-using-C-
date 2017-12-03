#include "NormalBall.h"
#include "Ball.h"
#include<math.h>



NormalBall::NormalBall(LTexture* image, float x, float y)
{
    this->objectType = ObjectBallType;
    type = NormalBallType;
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 153.5;
    spriteClips[ 0 ].y = 320;
    spriteClips[ 0 ].w = 24;
    spriteClips[ 0 ].h = 24;


//    //Frame 1
//    spriteClips[ 1 ].x = 128;
//    spriteClips[ 1 ].y =   0;
//    spriteClips[ 1 ].w = 128;
//    spriteClips[ 1 ].h = 96;
//
//    //Frame 2
//    spriteClips[ 2 ].x = 256;
//    spriteClips[ 2 ].y = 0;
//    spriteClips[ 2 ].w = 128;
//    spriteClips[ 2 ].h = 96;

//    x=0;
//    y=0;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    this->shouldMove = false;

    friction = 0.50f;
    SetDirection(-1,-1);
}


NormalBall::~NormalBall()
{
    spriteSheetTexture = NULL;
}

void NormalBall::SetAlive(bool alive)
{
    this->alive = alive;
}

bool NormalBall::GetAlive()
{
    return alive;
}



void NormalBall::Move(float x, float y)
{
    this->y += diry*y;
    this->x += dirx*x;
}

void NormalBall::Render(long int frame,SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
void NormalBall::didCollide(CollisionInfo info){
    Ball::didCollide(info);
}
