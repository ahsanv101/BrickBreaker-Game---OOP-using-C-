#include "Ball.h"
#include<math.h>

//bool Ball::Collides(Board* other)
//    {
//    if (x + width > other->x  && x < other->x + other->width &&
//        y + height  > other->y +40 && y   < other->y + other->height)
//        {
//          return true;
//        }
//    return false;
//    }
//bool Ball::Collide2(Bat* other)
//    {
//    if (x + width > other->x -40 && x +40 < other->x + other->width &&
//        y + height  > other->y && y   < other->y + other->height)
//        {
//
//          return true;
//        }
//    return false;
//    }
//bool Ball::Collidesleft(Board* other)
//    {
//    if (this->x <= other->x)
//        {
//
//          return true;
//        }
//    return false;
//    }
//bool Ball::Collidesright(Board* other)
//    {
//    if (this->x + this->width >= other->x + other->width)
//        {
//
//          return true;
//        }
//    return false;
//    }
//
//
//Ball::Ball(LTexture* image, float x, float y)
//{
//    spriteSheetTexture = image;
//
//
//    //Frame 0
//    spriteClips[ 0 ].x =   153.5;
//    spriteClips[ 0 ].y =   320;
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
////    x=0;
////    y=0;
//    this->x = x;
//    this->y = y;
//
//    this->width = spriteClips[ 0 ].w;
//    this->height = spriteClips[ 0 ].h;
//
//    friction = 0.50f;
//    SetDirection(1,1);
//}
//
//
//Ball::~Ball()
//{
//    spriteSheetTexture = NULL;
//}
//
//void Ball::SetAlive(bool alive)
//{
//    this->alive = alive;
//}
//
//bool Ball::GetAlive()
//{
//    return alive;
//}
//
//
void Ball::SetDirection(float dirx, float diry)
{
    float length = sqrt(dirx * dirx + diry * diry);
    this->dirx = BALL_SPEED * (dirx / length);
    this->diry = BALL_SPEED * (diry / length);
}
void Ball::Move(){
    if(shouldMove){
        Move(1,1);
    }
}
//
//void Ball::Move(float xx, float yy)
//{
//    y +=diry* yy;
//    x +=dirx* xx;
//
//
//}
//
//
//void Ball::Render(long int& frame, SDL_Renderer* gRenderer)
//{
//    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//}


