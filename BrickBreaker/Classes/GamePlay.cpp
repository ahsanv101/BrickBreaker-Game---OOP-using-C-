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
LTexture kSpriteSheetTexture;
LTexture vSpriteSheetTexture;
LTexture pSpriteSheetTexture;
//LTexture xSpriteSheetTexture;
GamePlay::GamePlay(SDL_Renderer* renderer)
{

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
        bat = new Bat(&kSpriteSheetTexture, (float)SCREEN_WIDTH/2, 630);
        ball = new NormalBall(&vSpriteSheetTexture, bat->x, bat->y-23);
        SDL_Surface* surface = IMG_Load("images/finalsprites.png");
        bricktexture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

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

        brickoffsetx = 0;
        brickoffsety = 0;
}



GamePlay::~GamePlay()
{

}






void GamePlay::Render( SDL_Renderer* renderer,float delta)
{
//    bat->Render(frame,renderer);
    SDL_SetRenderDrawColor( renderer,100,100,100, 255 );
    SDL_RenderFillRect(renderer,&(this->side1));
    SDL_RenderFillRect(renderer,&(this->side2));
    SDL_RenderFillRect(renderer,&(this->side3));
    int j=0;
    Node* temp = brickstorender.returnhead();
    while(temp!=NULL){
        Brick brick = *temp->brick;
        int i= temp->position%12;
        j = temp->y;

        temp=temp->next;

        // Check if the brick exists
        if(!brick.state)
        {
            continue;
        }


        SDL_Rect srcrect;

        srcrect.x = 9 + (brick.type) * BOARD_BRWIDTH;
        srcrect.y = 61 + ((0) * BOARD_BRHEIGHT);
        srcrect.w = BOARD_BRWIDTH;
        srcrect.h = BOARD_BRHEIGHT;

        SDL_Rect dstrect;
        dstrect.x = brickoffsetx + x + i * BOARD_BRWIDTH;
        dstrect.y = brickoffsety + y + j * BOARD_BRHEIGHT;
        dstrect.w = BOARD_BRWIDTH;
        dstrect.h = BOARD_BRHEIGHT;

        SDL_RenderCopy(renderer, bricktexture, &srcrect, &dstrect);
    }
/*

    // Render sides
    SDL_Rect dstrect;
    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = 16;
    dstrect.h = 600;
    SDL_RenderCopy(renderer, sidetexture, 0, &dstrect);

    dstrect.x = 1024 - 16;
    dstrect.y = 0;
    dstrect.w = 16;
    dstrect.h = 600;
    SDL_RenderCopy(renderer, sidetexture, 0, &dstrect);
    */
}


void GamePlay::CreateLevel() {

    std::string content;
	//opening file
    std::ifstream readfile;
    readfile.open("bricks.txt");
    int j=0;
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
                brickstorender.Enqueue(brick, i, j);
            }
            if(i>=content.length()-1 && j<BOARD_HEIGHT)
            {
                j++;

            }

        }
    }
}

