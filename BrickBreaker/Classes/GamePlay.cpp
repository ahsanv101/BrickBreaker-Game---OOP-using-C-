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

GamePlay::GamePlay(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    loadMedia();
    shoot = false;

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
    ball = new NormalBall(&batBallSpriteSheet, bat->x, bat->y-24);


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
    SDL_SetRenderDrawColor( renderer,100,100,100,255);
    SDL_RenderFillRect(renderer,&(this->side1));
    SDL_RenderFillRect(renderer,&(this->side2));
    SDL_RenderFillRect(renderer,&(this->side3));
    bat->Render(renderer);
    ball->Render(renderer);
    board->Display(renderer);
    if(!isBallAlive(ball)){
        delete ball;
        Sleep(1000);
        ball = new NormalBall(&batBallSpriteSheet, bat->x,bat->y-24);
    }


    //Code for Ball-Side Collision Detection
    if (detectCollisionBetween(side2, ball) == Vertical){
        ball->diry *= -1;
    }
    if (detectCollisionBetween(side1, ball) == Horizontal || detectCollisionBetween(side3, ball) == Horizontal)
    {
        ball->dirx *= -1;
    }

    //Code for Ball-Bat Collision Detection
    if (detectCollisionBetween(bat, ball) && ball->shouldMove){
//            float ballcenterx = ball->x + ball->width / 2.0f;
//            int hitx = ballcenterx - bat->x;
//           // cout<<bat->x<<endl;
//            cout<<hitx<<endl;
//            if (hitx>0){
//                ///ball->SetDirection(1,1);
        ball->diry *= -1;
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
        ball->shouldMove = true;
    }
    if(event[ SDL_SCANCODE_RIGHT ]){
        if(bat->x+bat->width/2>=this->side3.x || !ball->shouldMove){return;}
        bat->Move(RIGHT);
    }
    if(event[ SDL_SCANCODE_LEFT ]){

        if (bat->x-bat->width/2<=this->side1.x+this->side1.w || !ball->shouldMove){return;}
        bat->Move(LEFT);
    }
}

bool GamePlay::loadMedia(){
    if( !backgroundSprite.LoadFromFile( "Images/bgimage.png", renderer  ) )
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
bool GamePlay::detectCollisionBetween(Bat* bat, Ball* ball){
    bool isInXRange = (ball->x+(ball->width/2) >= bat->x-(bat->width/2)) && (ball->x-(ball->width/2)) <= (bat->x + (bat->width/2));
    float batOriginY = bat->y - bat->height/2;
    float ballMaxY = ball->y + ball->height/2;
    return isInXRange && ballMaxY-batOriginY <= 3 && ballMaxY-batOriginY > -1;
}
CollisionType GamePlay::detectCollisionBetween(const SDL_Rect& wall, Ball* ball){
    //this means the wall is horizontal
    if(wall.w > wall.h){
        if(ball->y-ball->height/2<=wall.y+wall.h){
            return Vertical;
        }
        return None;
    }
    //this means the wall is at the left side of the level.
    if(wall.x-5 < 0){
        if(ball->x-(ball->width/2) <= wall.w){
            return Horizontal;
        }
        return None;
    }
    //if the code reaches here, this means the wall is longitudinal and is at the right side.
    if(ball->x+(ball->width/2) >= wall.x){
        return Horizontal;
    }
    return None;
}

CollisionType GamePlay::detectCollisionBetween(Brick* brick, Ball* ball){
    return None;
}
bool GamePlay::isBallAlive(Ball* ball){
    return ball->y-ball->height<=SCREEN_HEIGHT;
}
