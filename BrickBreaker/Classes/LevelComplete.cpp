#include "Pop-Up.h"
#include "Button.h"
#include "GamePlay.h"
#include "Menu.h"
#include "LevelComplete.h"
#include <iostream>

LevelComplete::LevelComplete(){
    renderer = NULL;
}
LevelComplete::LevelComplete(SDL_Renderer* renderer){
    this->renderer = renderer;
    if(loadMedia()){
        nextLevel = Button(" Next ", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)}, &gSpriteSheetTexture, &buttonSpriteTexture, Brown);
        restart = Button("Restart", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+70}, &gSpriteSheetTexture, &buttonSpriteTexture, Brown);
        quit = Button(" Quit ", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+140}, &gSpriteSheetTexture, &buttonSpriteTexture, Brown);
    }else{
        std::cout<<"Error loading media in Pop-up class";
    }

}
void LevelComplete::show()
{
    backSpriteSheetTexture.Render(275,180,0,0.0,NULL,SDL_FLIP_NONE,renderer);
    nextLevel.Draw(renderer);
    restart.Draw(renderer);
    quit.Draw(renderer);
}
void LevelComplete::click(int x, int y, MouseEventType eventType, ScreenManager** parentPointer, Pop_Up** selfPointer){
    if(eventType == ClickDown){
        if(nextLevel.pointLiesInBounds(x,y)){
            nextLevel.setIsClicked(true);
            std::cout<<"nextLevel Button Down"<<std::endl;
        }else if(restart.pointLiesInBounds(x,y)){
            restart.setIsClicked(true);
            std::cout<<"Restart Button Down"<<std::endl;
        }else if(quit.pointLiesInBounds(x,y)){
            quit.setIsClicked(true);
            std::cout<<"Quit Button Down"<<std::endl;
        }
    }else if(eventType == ClickUp){
        if(nextLevel.pointLiesInBounds(x,y) && nextLevel.getIsClicked()){
            std::cout<<"nextLevel Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(restart.pointLiesInBounds(x,y) && restart.getIsClicked()){
            std::cout<<"Restart Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(quit.pointLiesInBounds(x,y) && quit.getIsClicked()){
            std::cout<<"Quit Button Up"<<std::endl;
            *parentPointer = new Menu(this->renderer);
        }
        nextLevel.setIsClicked(false);
        restart.setIsClicked(false);
        quit.setIsClicked(false);
    }
}
void LevelComplete::keyboardEvent(const Uint8* event, ScreenManager** parentPointer, Pop_Up** selfPointer)
{

}

LevelComplete::~LevelComplete()
{

}

bool LevelComplete::loadMedia()
{
	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/final2.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !backSpriteSheetTexture.LoadFromFile( "Images/levelcomplete.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		return false;
	}
	if(!buttonSpriteTexture.LoadFromFile("Images/button.jpg",renderer))
    {
        printf( "Failed to load sprite sheet texture!\n" );
		return false;
    }
	return true;
}
