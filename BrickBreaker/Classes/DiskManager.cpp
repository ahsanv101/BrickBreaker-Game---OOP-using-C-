#include "DiskManager.h"
#include "NormalBall.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

DiskManager::DiskManager()
{
    //ctor
}
void DiskManager::SaveGame(const GamePlay& gameplay){
    ofstream* editFile = new ofstream();
    editFile->open("Levels/SavedInstance.txt");

    //Saving Balls
    saveBalls(gameplay, editFile);

    //Saving Bricks
    saveBricks(gameplay, editFile);

    //Saving Bat
    *editFile<<endl<<"Bat:";
    *editFile<<endl<<">"<<Bat::GetInstance()->width;

    *editFile<<endl<<"Game:";
    //Should save score, lives, levelCount and more...
    editFile->close();
}

GamePlay* DiskManager::LoadGame(SDL_Renderer* renderer){

    //Loading the file if it is saved.
    ifstream readfile("Levels/SavedInstance.txt");
    string name2;
    if(!readfile){
        return NULL;
    }
    if(!(readfile >> name2)){
        return NULL;
    }

    //Loading textures for Bat & Ball
    LTexture* backgroundTexture = new LTexture;
    LTexture* batBallTexture = new LTexture;
    if( !backgroundTexture->LoadFromFile( "Images/bgimage.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
	}
	if( !batBallTexture->LoadFromFile( "Images/finalsprites.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
	}

    //Defining Objects of GamePlay
    Bat* bat = Bat::GetInstance();
    bat->SetValue(batBallTexture, (float)SCREEN_WIDTH/2, 630);
    Board* board = new Board(16, 5, 768, 600, renderer);
    float ballx, bally, ballDirX, ballDirY;
    int ballSpeed;

    if(name2.find("Ball") != string::npos){
        while(readfile >> name2){
            if(name2.find(">") == string::npos){
                break;
            }
            int j = 0;
            for(int i = 1; i < name2.length(); i++){
                string::size_type commaIndex = name2.find(",", i);
                switch(j){
                case 0:
                    ballx = atof(name2.substr(i, commaIndex-i).c_str());
                    break;
                case 1:
                    bally = atof(name2.substr(i, commaIndex-i).c_str());
                    break;
                case 2:
                    ballDirX = atof(name2.substr(i, commaIndex-i).c_str());
                    break;
                case 3:
                    ballDirY = atof(name2.substr(i, commaIndex-i).c_str());
                    break;
                case 4:
                    //ball->diry = atof(name2.substr(i, commaIndex-i));
                    break;
                case 5:
                    ballSpeed = atoi(name2.substr(i, commaIndex-i).c_str());
                    break;
                }
                if(commaIndex == string::npos){
                    break;
                }
                i = commaIndex;
                j++;
            }
        }
    }

    Ball* ball = new NormalBall(batBallTexture, ballx, bally);
    ball->SetDirection(ballDirX, ballDirY);
    ball->BALL_SPEED = ballSpeed;

    if(name2.find("Brick") != string::npos){
        int k = 0;
        while(readfile >> name2 && k <= BOARD_HEIGHT){
            if(name2.find(">") == string::npos){
                break;
            }
            for(int l=1; l<name2.length(); l++)
            {
                if((l-1)==BOARD_WIDTH)
                {
                    break;
                }
                Brick* brick = new Brick();
                brick->state = true;
                int bricktype = atoi(name2.substr(l, 1).c_str());
                brick->type=rand()%3;
                brick->breaktype=bricktype;
                if(name2[l]=='3')
                {
                    brick->breaktype = 0;
                    brick->type=3;
                }else
                if(name2[l]=='-')
                {
                    continue;
                }
                board->Enqueue(brick, l-1, k);
            }
            k++;
        }
    }

    readfile.close();
    GamePlay* gamePlay = new GamePlay(renderer, ball, board, backgroundTexture, batBallTexture);

    return gamePlay;
}
void DiskManager::saveBricks(const GamePlay& gamePlay, ofstream* editFile){
    *editFile<<endl<<"Bricks:";
    Board* board = gamePlay.getBoard();
    Node* temp = board->getHead();
    for(int j = 0; j < BOARD_HEIGHT; j++){
        *editFile<<endl<<">";
        for(int i = 0; i<BOARD_WIDTH && temp->y == j; i++){
            if(temp->position == i){
                if(temp->brick->state){
                    *editFile<<(temp->brick->type == 3 ? 3 : temp->brick->breaktype);
                }else{
                    *editFile<<"-";
                }
                temp = temp->next;
            }else{
                *editFile<<"-";
            }
            if(!temp){
                *editFile<<endl;
                return;
            }
        }
    }
}
void DiskManager::saveBalls(const GamePlay& gamePlay, ofstream* editFile){
    *editFile<<"Balls:";
    Ball* ball = gamePlay.getBall();
    *editFile<<endl<<">"<<ball->x<<","<<ball->y<<","<<ball->dirx<<","<<ball->diry<<","<<1/*Type of ball for*/<<","<<ball->BALL_SPEED;
}
