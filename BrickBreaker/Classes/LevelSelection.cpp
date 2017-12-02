#include "Pop-Up.h"
#include "Button.h"
#include "GamePlay.h"
#include "Menu.h"
#include "LevelSelection.h"
#include <iostream>

LevelSelection::LevelSelection(){
    renderer = NULL;
}
LevelSelection::LevelSelection(SDL_Renderer* renderer){
    this->renderer = renderer;
    if(loadMedia()){
        l1 = Button("01", {(float)(SCREEN_WIDTH/2)-240,(int)(200)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l2 = Button("02", {(float)(SCREEN_WIDTH/2)-100, (int)(200)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l3 = Button("03", {(float)(SCREEN_WIDTH/2)-240, (int)(270)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l4 = Button("04", {(float)(SCREEN_WIDTH/2)-100, (int)(270)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l5 = Button("05", {(float)(SCREEN_WIDTH/2)-240, (int)(340)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l6 = Button("06", {(float)(SCREEN_WIDTH/2)-100, (int)(340)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l7 = Button("07", {(float)(SCREEN_WIDTH/2)-240, (int)(410)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l8 = Button("08", {(float)(SCREEN_WIDTH/2)-100, (int)(410)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l9 = Button("09", {(float)(SCREEN_WIDTH/2)-240, (int)(480)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        l10 = Button("10", {(float)(SCREEN_WIDTH/2)-100, (int)(480)}, &gSpriteSheetTexture, &buttonSpriteTexture, Green);
        circle = Button("Circle", {(float)(SCREEN_WIDTH/2)+200, (int)(200)}, &gSpriteSheetTexture, &buttonSpriteTexture, Red);
        diamond = Button("Diamond", {(float)(SCREEN_WIDTH/2)+200, (int)(270)}, &gSpriteSheetTexture, &buttonSpriteTexture, Red);
        wave = Button(" Wave ", {(float)(SCREEN_WIDTH/2)+200, (int)(340)}, &gSpriteSheetTexture, &buttonSpriteTexture, Red);
        backButton = Button(" Back ", {(float)(SCREEN_WIDTH/2)+200, (int)(480)}, &gSpriteSheetTexture, &buttonSpriteTexture, Brown);
    }else{
        std::cout<<"Error loading media in Pop-up class";
    }

}
void LevelSelection::show()
{
    backSpriteSheetTexture.Render(130,0,0,0.0,NULL,SDL_FLIP_NONE,renderer);
    l1.Draw(renderer);
    l2.Draw(renderer);
    l3.Draw(renderer);
    l4.Draw(renderer);
    l5.Draw(renderer);
    l6.Draw(renderer);
    l7.Draw(renderer);
    l8.Draw(renderer);
    l9.Draw(renderer);
    l10.Draw(renderer);
    circle.Draw(renderer);
    diamond.Draw(renderer);
    wave.Draw(renderer);
    backButton.Draw(renderer);
}
void LevelSelection::click(int x, int y, MouseEventType eventType, ScreenManager** parentPointer, Pop_Up** selfPointer){
    if(eventType == ClickDown){
        if(l1.pointLiesInBounds(x,y)){
            l1.setIsClicked(true);
            std::cout<<"L1 Button Down"<<std::endl;
        }else if(l2.pointLiesInBounds(x,y)){
            l2.setIsClicked(true);
            std::cout<<"L2 Button Down"<<std::endl;
        }else if(l3.pointLiesInBounds(x,y)){
            l3.setIsClicked(true);
            std::cout<<"L3 Button Down"<<std::endl;
        }else if(l4.pointLiesInBounds(x,y)){
            l4.setIsClicked(true);
            std::cout<<"L4 Button Down"<<std::endl;
        }else if(l5.pointLiesInBounds(x,y)){
            l5.setIsClicked(true);
            std::cout<<"L5 Button Down"<<std::endl;
        }else if(l6.pointLiesInBounds(x,y)){
            l6.setIsClicked(true);
            std::cout<<"L6 Button Down"<<std::endl;
        }else if(l7.pointLiesInBounds(x,y)){
            l7.setIsClicked(true);
            std::cout<<"L7 Button Down"<<std::endl;
        }else if(l8.pointLiesInBounds(x,y)){
            l8.setIsClicked(true);
            std::cout<<"L8 Button Down"<<std::endl;
        }else if(l9.pointLiesInBounds(x,y)){
            l9.setIsClicked(true);
            std::cout<<"L9 Button Down"<<std::endl;
        }else if(l10.pointLiesInBounds(x,y)){
            l10.setIsClicked(true);
            std::cout<<"L10 Button Down"<<std::endl;
        }else if(circle.pointLiesInBounds(x,y)){
            circle.setIsClicked(true);
            std::cout<<"Circle Button Down"<<std::endl;
        }else if(diamond.pointLiesInBounds(x,y)){
            diamond.setIsClicked(true);
            std::cout<<"Diamond Button Down"<<std::endl;
        }else if(wave.pointLiesInBounds(x,y)){
            wave.setIsClicked(true);
            std::cout<<"Wave Button Down"<<std::endl;
        }else if(backButton.pointLiesInBounds(x,y)){
            backButton.setIsClicked(true);
            std::cout<<"Back Button Down"<<std::endl;
        }
    }else if(eventType == ClickUp){
        if(l1.pointLiesInBounds(x,y) && l1.getIsClicked()){
            std::cout<<"L1 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
            //*selfPointer = NULL;
        }else if(l2.pointLiesInBounds(x,y) && l2.getIsClicked()){
            std::cout<<"L2 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l3.pointLiesInBounds(x,y) && l3.getIsClicked()){
            std::cout<<"L3 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l4.pointLiesInBounds(x,y) && l4.getIsClicked()){
            std::cout<<"L4 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l5.pointLiesInBounds(x,y) && l5.getIsClicked()){
            std::cout<<"L5 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l6.pointLiesInBounds(x,y) && l6.getIsClicked()){
            std::cout<<"L6 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l7.pointLiesInBounds(x,y) && l7.getIsClicked()){
            std::cout<<"L7 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l8.pointLiesInBounds(x,y) && l8.getIsClicked()){
            std::cout<<"L8 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l9.pointLiesInBounds(x,y) && l9.getIsClicked()){
            std::cout<<"L9 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(l10.pointLiesInBounds(x,y) && l10.getIsClicked()){
            std::cout<<"L10 Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(circle.pointLiesInBounds(x,y) && circle.getIsClicked()){
            std::cout<<"Circle Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(diamond.pointLiesInBounds(x,y) && diamond.getIsClicked()){
            std::cout<<"Diamond Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(wave.pointLiesInBounds(x,y) && wave.getIsClicked()){
            std::cout<<"Wave Button Up"<<std::endl;
            *parentPointer = new GamePlay(this->renderer);
        }else if(backButton.pointLiesInBounds(x,y) && backButton.getIsClicked()){
            std::cout<<"Back Button Up"<<std::endl;
            *selfPointer= NULL;
        }
        l1.setIsClicked(false);
        l2.setIsClicked(false);
        l3.setIsClicked(false);
        l4.setIsClicked(false);
        l5.setIsClicked(false);
        l6.setIsClicked(false);
        l7.setIsClicked(false);
        l8.setIsClicked(false);
        l9.setIsClicked(false);
        l10.setIsClicked(false);
        circle.setIsClicked(false);
        diamond.setIsClicked(false);
        wave.setIsClicked(false);
        backButton.setIsClicked(false);
    }
}
void LevelSelection::keyboardEvent(const Uint8* event, ScreenManager** parentPointer, Pop_Up** selfPointer){

}
LevelSelection::~LevelSelection(){

}

bool LevelSelection::loadMedia()
{
	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/final2.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !backSpriteSheetTexture.LoadFromFile( "Images/level.png", renderer  ) )
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
