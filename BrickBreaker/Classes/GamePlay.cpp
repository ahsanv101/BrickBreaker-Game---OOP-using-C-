#include "GamePlay.h"
#include "Bat.h"
#include "NormalBall.h"
#include "Board.h"

#include<string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "windows.h"
#include "FireBall.h"
#include "ThroughBall.h"
#include "NormalFire.h"
#include "MissileFire.h"

GamePlay::GamePlay(long int* frame,SDL_Renderer* renderer)
{
    this->frame = frame;
    this->renderer = renderer;
    loadMedia();
    blast = false;
    shoot = false;
    MisActivate = false;
    FireActivate = false;
    ThroughActivate = false;
    NormalActivate = false;
    IspeedActivate = false;
    dspeedActivate = false;
    this->side1.h=650;
    this->side1.w=5;
    this->side1.x=0;
    this->side1.y=0;

    this->side2.h=5;
    this->side2.w=1000;
    this->side2.x=0;
    this->side2.y=0;

    this->side3.h=650;
    this->side3.w=5;
    this->side3.x=1000-5;
    this->side3.y=0;

    bat = new Bat(&batBallSpriteSheet, (float)SCREEN_WIDTH/2, 630);
    ball = new NormalBall(&batBallSpriteSheet, bat->x, bat->y-23);
    //fire = new NormalFire(&batBallSpriteSheet, bat->x, bat->y-23);
    Missile  = new MissileFire(&batBallSpriteSheet, bat->x, bat->y-23);









    /*
    surface = IMG_Load("images/side.png");
    sidetexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    */

    srand(time(0));

    x = 16;
    y = 0;
    width = 768;
    height = 600;

    CreateLevel();
}



GamePlay::~GamePlay(){
    //Free all images loaded
}






void GamePlay::show()
{

    backgroundSprite.Render(0,0,0,0.0,NULL, SDL_FLIP_NONE, renderer);
    SDL_SetRenderDrawColor( renderer,100,100,100, 255 );
    SDL_RenderFillRect(renderer,&(this->side1));
    SDL_RenderFillRect(renderer,&(this->side2));
    SDL_RenderFillRect(renderer,&(this->side3));
    bat->Render(renderer);
    ball->Render(this->frame,renderer);
    board->Display(renderer);

    if (*frame%20 ==0 and count<10)
    {

        fire=new NormalFire(&batBallSpriteSheet, bat->x, bat->y-23);
        q.Enqueue(fire);
        count++;


    }

    if(blast )
    {
        q.Render(this->frame,renderer);
        q.Move();

        //fire = new NormalFire(&batBallSpriteSheet, bat->x, bat->y-23);
        //fire->Render(this->frame,renderer);
        //fire->Move();
        //q.Render(this->frame,renderer);
        //q.Move();

    }
    if (MisActivate)
    {
        //blast = false;
        //delete fire;
        Missile->Render(this->frame,renderer);
        Missile->Move();

        //blast = true;
        //fire->Move();

    }
    if(IspeedActivate)
    {
        //dspeedActivate = false;
        ball->BALL_SPEED = 15;

    }
    if (dspeedActivate)
    {
        //IspeedActivate = false;
        ball->BALL_SPEED = 5;
    }

    if(ball->y-ball->height/2 - 20>SCREEN_HEIGHT){
        delete ball;
        Sleep(1000);
        FireActivate = false;
        ThroughActivate = false;
        NormalActivate = false;
        IspeedActivate = false;
        dspeedActivate = false;
        ball = new NormalBall(&batBallSpriteSheet, bat->x,bat->y-24);
        shoot = false;
    }
    if (shoot)
    {

        ball->Move(1,-1);
    }
    if (NormalActivate)
    {
         int speedx = ball->dirx;
         int speedy = ball->diry;
         int x = ball->x;
         int y = ball->y;
         int sp = ball->BALL_SPEED;
         delete ball;
         ball = new NormalBall(&batBallSpriteSheet, x,y);
         ball->dirx = speedx;
         ball->diry = speedy;
         ball->BALL_SPEED = sp;
    }
    if (FireActivate)
    {
         //ThroughActivate = false;
         int speedx = ball->dirx;
         int sp = ball->BALL_SPEED;
         int speedy = ball->diry;

         int x = ball->x;
         int y = ball->y;
         delete ball;
         ball = new FireBall(&batBallSpriteSheet, x,y);
         ball->dirx = speedx;
         ball->diry = speedy;
         ball->BALL_SPEED = sp;
    }
    if (ThroughActivate)
    {
         //FireActivate  = false;
         int speedx = ball->dirx;
         int speedy = ball->diry;
         int sp = ball->BALL_SPEED;
         int x = ball->x;
         int y = ball->y;
         delete ball;
         ball = new ThroughBall(&batBallSpriteSheet, x,y);
         ball->dirx = speedx;
         ball->diry = speedy;
         ball->BALL_SPEED = sp;
    }


    //Code for Ball-Side Collision Detection
    if (ball->y-ball->height/2<=this->side2.y+this->side2.h){
        ball->diry *= -1;
    }
    if (ball->x-ball->width/2<=this->side1.x+this->side1.w)
    {
        ball->dirx *= -1;
    }
    if(ball->x+ball->width/2>=this->side3.x+this->side3.w){
        ball->dirx *= -1;
    }

    //Code for Ball-Bat Collision Detection
    if (ball->Collide2(bat)){
//            float ballcenterx = ball->x + ball->width / 2.0f;
//            int hitx = ballcenterx - bat->x;
//           // cout<<bat->x<<endl;
//            cout<<hitx<<endl;
//            if (hitx>0){
//                ///ball->SetDirection(1,1);

                        float ballcenterx = ball->x + ball->width / 2.0f;
                        int hitx = ballcenterx - bat->x;
                        //cout<<hitx<<endl;
                        //ball->SetDirection(-1,1);
                        if (hitx>12)
                            {
                                ball->SetDirection(1,1);
                                //ball->diry *= -1;
                                //ball->dirx *=1;
                                //ball->SetDirection(-1,1);

                            }
                        else if (hitx<12)
                            {
                                ball->SetDirection(-1,1);
                                //ball->diry *= -1;
                                //ball->dirx*=1;
                                //ball->SetDirection(1,1);
                            }
                        else if (hitx==12)
                            {
                                ball->SetDirection(0,1);
                                //ball->dirx *= 0.1;
                                //ball->SetDirection(0,1);
                            }
//            }
//            else if (hitx<0){
//                //ball->SetDirection(-1,1);
//                ball->diry *= -1;
//            }
//            else if (hitx==0){
//                //ball->SetDirection(0,1);
//                ball->diry *= -1;
//            }

    }
}


void GamePlay::CreateLevel() {
    board = new Board(x, y, width, height, renderer);

    std::string content;
	//opening file
    std::ifstream readfile;
    readfile.open("bricks.txt");
    int j = 0;
    while (getline(readfile, content))
    {
        for(int i=0; i<content.length(); i++)
        {
            if(content[i]=='*')
            {
                int bricktype = rand()%3;
                //cout<<bricktype<<endl;
                Brick* brick = new Brick;
                brick->type=rand()%4;
                brick->breaktype=bricktype;
                brick->state = true;
                //cout<<brick->breaktype<<endl;
                board->Enqueue(brick, i, j);
            }
            if(i==content.length()-1 && j<=BOARD_HEIGHT)
            {
                j++;

            }
        }
        if(j > BOARD_HEIGHT){
            break;
        }
    }
}
void GamePlay::click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer){}

void GamePlay::keyboardEvent(const Uint8* event, ScreenManager** selfPointer){
    if(event[ SDL_SCANCODE_SPACE ]){
        shoot = true;
    }
    if(event[ SDL_SCANCODE_DOWN ]){
        FireActivate = true;

    }
    if(event[ SDL_SCANCODE_UP ]){
        ThroughActivate = true;
    }
    if(event[ SDL_SCANCODE_1 ]){
        NormalActivate = true;
    }
    if(event[ SDL_SCANCODE_Z ]){
        IspeedActivate = true;
    }
    if(event[ SDL_SCANCODE_X ]){
        dspeedActivate = true;
    }
    if(event[ SDL_SCANCODE_C ]){
        blast= true;
    }
    if(event[ SDL_SCANCODE_V ]){
        MisActivate = true;
    }


    if(event[ SDL_SCANCODE_RIGHT ]){
        if(bat->x+bat->width/2>=this->side3.x){}
        else if (ball->x == bat->x && ball->y == bat->y-24){}
        else{
            bat->Move(RIGHT);
        }
    }
    if(event[ SDL_SCANCODE_LEFT ]){

        if (bat->x-bat->width/2<=this->side1.x+this->side1.w){}
        else if (ball->x == bat->x && ball->y == bat->y-24){}
        else{
            bat->Move(LEFT);
        }

    }

}

bool GamePlay::loadMedia(){
    if( !backgroundSprite.LoadFromFile( "Images/bgimages.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !batBallSpriteSheet.LoadFromFile( "Images/finalsprites.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	return true;
}
