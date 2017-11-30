#include "FireBall.h"
#include "Ball.h"
#include<math.h>

bool FireBall::Collides(Board* other)
    {
    if (x + width > other->x  && x < other->x + other->width &&
        y + height  > other->y +40 && y   < other->y + other->height)
        {
          return true;
        }
    return false;
    }
bool FireBall::Collide2(Bat* other)
    {
    if (x + width > other->x -40 && x +40 < other->x + other->width &&
        y + height  > other->y && y   < other->y + other->height)
        {

          return true;
        }
    return false;
    }
bool FireBall::Collidesleft(Board* other)
    {
    if (this->x <= other->x)
        {

          return true;
        }
    return false;
    }
bool FireBall::Collidesright(Board* other)
    {
    if (this->x + this->width >= other->x + other->width)
        {

          return true;
        }
    return false;
    }


FireBall::FireBall(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


//    //Frame 0
    spriteClips[ 0 ].x = 200;
    spriteClips[ 0 ].y = 265;
    spriteClips[ 0 ].w = 28;
    spriteClips[ 0 ].h = 24;


    //Frame 1
    spriteClips[ 1 ].x = 270;
    spriteClips[ 1 ].y = 265;
    spriteClips[ 1 ].w = 34;
    spriteClips[ 1 ].h = 34;

//    //Frame 2
    spriteClips[ 2 ].x = 130;
    spriteClips[ 2 ].y = 265;
    spriteClips[ 2 ].w = 24;
    spriteClips[ 2 ].h = 24;

//    x=0;
//    y=0;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.50f;
    SetDirection(-1,-1);
}


FireBall::~FireBall()
{
    spriteSheetTexture = NULL;
}

void FireBall::SetAlive(bool alive)
{
    this->alive = alive;
}

bool FireBall::GetAlive()
{
    return alive;
}


void FireBall::Move(float xx, float yy)
{
    y +=diry* yy;
    x +=dirx* xx;


}

void FireBall::Render(long int frame,SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}


