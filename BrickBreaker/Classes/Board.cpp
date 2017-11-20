
#include "Board.h"
#include<string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

Board::Board(SDL_Renderer* renderer): Object(renderer) {
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

Board::~Board() {
    // Clean resources
    SDL_DestroyTexture(bricktexture);
    SDL_DestroyTexture(sidetexture);
}

void Board::Update(float delta) {

}

void Board::Render(float delta) {// Render bricks
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

void Board::CreateLevel() {

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

