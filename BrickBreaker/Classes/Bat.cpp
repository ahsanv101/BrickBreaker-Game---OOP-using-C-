#include "Bat.h"
#include "Board.h"
Bat::Bat()
{
    //ctor
}

Bat::~Bat()
{
    spriteSheetTexture = NULL;
}

bool Bat::Collides(Board* other) {
    if (x + width > other->x +20 && x - 60 < other->x + other->width &&
        y + height > other->y && y < other->y + other->height) {
        return true;
    }
    return false;
}

float Bat::GetReflection(float hitx) {
    // Make sure the hitx variable is within the width of the paddle
    if (hitx < 0)
        {
           hitx = 0;
        }
    else if (hitx > this->width)
        {
            hitx = this->width;
        }

    // Everything to the left of the center of the paddle is reflected to the left
    // while everything right of the center is reflected to the right
    hitx -= this->width / 2.0f;

    // Scale the reflection, making it fall in the range -2.0f to 2.0f
    return 2.0f * (hitx / (this->width / 2.0f));
}



Bat::Bat(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   280;
    spriteClips[ 0 ].w = 115;
    spriteClips[ 0 ].h = 30;

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

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.99f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}




void Bat::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Bat::GetAlive()
{
    return alive;
}
//void Move(int direction, SDL_Rect& side)
//{
//    if(direction==LEFT )
//    {
//        if (checkCollision(spriteClips[0], side)
//            {
//                this->x -= this->speedx;
//                spriteClips[0].x = this->x;
//            }
//        speedx = -7;
//        x=x+speedx;
//    }
//    if(direction==RIGHT)
//    {
//        if (checkCollision(spriteClips[0], side)
//            {
//                this->x -= this->speedx;
//                spriteClips[0].x = this->x;
//            }
//        speedx = 7;
//        x=x+speedx;
//    }
//
//}
void Bat::Move(int direction)
{

    if(direction==LEFT )
    {
        speedx = -8;
        x=x+speedx;
    }

    if(direction==RIGHT)
    {
        speedx = 8;
        x=x+speedx;
    }

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

void Bat::Move()
{

     speedy = speedy * friction;



     speedx = speedx * friction;
     x = x + speedx;


      y = y + speedy;
}

void Bat::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

