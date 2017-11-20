#include "GamePlay.h"
#include "Bat.h"
#include "NormalBall.h"
#include "Board.h"
LTexture kSpriteSheetTexture;
LTexture vSpriteSheetTexture;
LTexture pSpriteSheetTexture;
//LTexture xSpriteSheetTexture;
GamePlay::GamePlay()
{
        bat = new Bat(&kSpriteSheetTexture, (float)SCREEN_WIDTH/2, 630);
        ball = new NormalBall(&vSpriteSheetTexture, bat->x, bat->y-23);
}



GamePlay::~GamePlay()
{

}

void GamePlay::Render(long int& frame, SDL_Renderer* gRenderer)
{
    bat->Render(frame,gRenderer);
}
