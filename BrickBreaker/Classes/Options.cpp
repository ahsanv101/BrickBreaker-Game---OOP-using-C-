#include "Pop-Up.h"
#include "Button.h"
#include "GamePlay.h"
#include "Menu.h"
#include "Options.h"
#include <iostream>

Options::Options(){
    renderer = NULL;
}
Options::Options(SDL_Renderer* renderer){
    this->renderer = renderer;
    if(loadMedia()){
        resume = Button("Resume", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)-50}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        save = Button(" Save ", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+20}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        restart = Button("Restart", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+90}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        quit = Button(" Quit ", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+160}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
    }else{
        std::cout<<"Error loading media in Pop-up class";
    }

}
void Options::show()
{
    backSpriteSheetTexture.Render(239,80,0,0.0,NULL,SDL_FLIP_NONE,renderer);
    resume.Draw(renderer);
    save.Draw(renderer);
    restart.Draw(renderer);
    quit.Draw(renderer);
}
void Options::click(int x, int y, MouseEventType eventType, ScreenManager** parentPointer, Pop_Up** selfPointer){
    if(eventType == ClickDown){
        if(resume.pointLiesInBounds(x,y)){
            resume.setIsClicked(true);
            std::cout<<"Resume Button Down"<<std::endl;
        }else if(save.pointLiesInBounds(x,y)){
            save.setIsClicked(true);
            std::cout<<"Save Button Down"<<std::endl;
        }else if(restart.pointLiesInBounds(x,y)){
            restart.setIsClicked(true);
            std::cout<<"Restart Button Down"<<std::endl;
        }else if(quit.pointLiesInBounds(x,y)){
            quit.setIsClicked(true);
            std::cout<<"Quit Button Down"<<std::endl;
        }
    }else if(eventType == ClickUp){
        if(resume.pointLiesInBounds(x,y) && resume.getIsClicked()){
            std::cout<<"Resume Button Up"<<std::endl;
            *selfPointer = NULL;
        }else if(save.pointLiesInBounds(x,y) && save.getIsClicked()){
            std::cout<<"Save Button Up"<<std::endl;
        }else if(restart.pointLiesInBounds(x,y) && restart.getIsClicked()){
            std::cout<<"Restart Button Up"<<std::endl;
            GamePlay* gamePlay = dynamic_cast<GamePlay*>(*parentPointer);
            *parentPointer = new GamePlay(this->renderer, gamePlay->getCurrentLevel());
        }else if(quit.pointLiesInBounds(x,y) && quit.getIsClicked()){
            std::cout<<"Quit Button Up"<<std::endl;
            *parentPointer = new Menu(this->renderer);
        }
        resume.setIsClicked(false);
        save.setIsClicked(false);
        restart.setIsClicked(false);
        quit.setIsClicked(false);
    }
}
void Options::keyboardEvent(const Uint8* event, ScreenManager** parentPointer, Pop_Up** selfPointer){

}
Options::~Options(){

}

bool Options::loadMedia()
{
	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/final2.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !backSpriteSheetTexture.LoadFromFile( "Images/pop_back.png", renderer  ) )
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