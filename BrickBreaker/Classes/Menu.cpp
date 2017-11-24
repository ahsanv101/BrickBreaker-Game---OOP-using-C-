#include "Menu.h"
#include "Button.h"
#include "GamePlay.h"
#include <iostream>

Menu::Menu(){
    renderer = NULL;
}
Menu::Menu(SDL_Renderer* renderer){
    this->renderer = renderer;
    if(loadMedia()){
        newGame = Button("New Game", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)}, &gSpriteSheetTexture);
        loadGame = Button("Load Game", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+70}, &gSpriteSheetTexture);
        exitGame = Button("Exit Game", {(float)SCREEN_WIDTH/2, (float)(SCREEN_HEIGHT/2)+140}, &gSpriteSheetTexture);
    }else{
        std::cout<<"Error loading media in Menu class";
    }

}
void Menu::show(){
    backSpriteSheetTexture.Render(0,0,0,0.0,NULL,SDL_FLIP_NONE,renderer);
    newGame.Draw(renderer);
    loadGame.Draw(renderer);
    exitGame.Draw(renderer);
}
void Menu::click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer){
    if(eventType == ClickDown){
        if(newGame.pointLiesInBounds(x,y)){
            newGame.setIsClicked(true);
            std::cout<<"New Game Button Down"<<std::endl;
        }else if(loadGame.pointLiesInBounds(x,y)){
            loadGame.setIsClicked(true);
            std::cout<<"Load Game Button Down"<<std::endl;
        }else if(exitGame.pointLiesInBounds(x,y)){
            exitGame.setIsClicked(true);
            std::cout<<"Exit Game Button Down"<<std::endl;
        }
    }else if(eventType == ClickUp){
        newGame.setIsClicked(false);
        exitGame.setIsClicked(false);
        loadGame.setIsClicked(false);
        if(newGame.pointLiesInBounds(x,y)){
            std::cout<<"New Game Button Up"<<std::endl;
            *selfPointer = new GamePlay(this->renderer);
        }else if(loadGame.pointLiesInBounds(x,y)){
            std::cout<<"Load Game Button Up"<<std::endl;
        }else if(exitGame.pointLiesInBounds(x,y)){
            std::cout<<"Exit Game Button Up"<<std::endl;
            *selfPointer = NULL;
        }
    }
}
void Menu::keyboardEvent(const Uint8* event, ScreenManager** selfPointer){

}
Menu::~Menu(){

}

bool Menu::loadMedia()
{
	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/final2.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !backSpriteSheetTexture.LoadFromFile( "Images/eg3.jpg", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		return false;
	}
	if(!splashSpriteSheetTexture.LoadFromFile("Images/eg3.jpg",renderer))
    {
        printf( "Failed to load sprite sheet texture!\n" );
		return false;
    }
	return true;
}
