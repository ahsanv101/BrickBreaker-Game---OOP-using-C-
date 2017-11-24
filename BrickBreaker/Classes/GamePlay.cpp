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

GamePlay::GamePlay(SDL_Renderer* renderer)
{
    this->renderer = renderer;

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
    bat = new Bat(&brickSpriteSheet, (float)SCREEN_WIDTH/2, 630);
    ball = new NormalBall(&brickSpriteSheet, bat->x, bat->y-23);


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

//    loadMedia();
    CreateLevel();
}



GamePlay::~GamePlay(){
    //Free all images loaded
}






void GamePlay::show()
{
    board->Display(renderer);
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
void GamePlay::keyboardEvent(const Uint8* event, ScreenManager** selfPointer){}

