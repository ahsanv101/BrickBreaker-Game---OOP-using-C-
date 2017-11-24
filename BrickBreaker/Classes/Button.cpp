#include"Button.h"
#include"Point.h"
#include<SDL.h>
#include<iostream>

Button::Button()
{
    isClicked = false;
}

Button::~Button()
{
    //dtor
}

Button::Button(std::string str, Point p, LTexture* texture){
    this->word = Word(texture, p.x, p.y, str);
    this->spriteSheetTexture = texture;
    this->center = p;
    isClicked = false;
}

void Button::Draw(SDL_Renderer* gRenderer){
    int length = this->word.length;
    int wordWidth = length*40;
    if (isClicked==true){
        SDL_Rect spriteClipLeft = {520, 65, 20, 60};
        SDL_Rect spriteClipRight = {580, 65, 20, 60};
        SDL_Rect spriteClipMiddle = {540, 65, 40, 60};
        int x = center.x - wordWidth/2 - 20;
        int y = center.y - 30;
        spriteSheetTexture->Render( x, y, &spriteClipLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        x += 20;
        for(int i = 0; i<length ; i++){
            spriteSheetTexture->Render( x, y, &spriteClipMiddle, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
            x += 40;
        }
        spriteSheetTexture->Render( x, y, &spriteClipRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        this->word.Render(gRenderer, true);
    }else{
        SDL_Rect spriteClipLeft = {440, 65, 20, 60};
        SDL_Rect spriteClipRight = {500, 65, 20, 60};
        SDL_Rect spriteClipMiddle = {460, 65, 40, 60};
        int x = center.x - wordWidth/2 - 20;
        int y = center.y - 30;
        spriteSheetTexture->Render( x, y, &spriteClipLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        x += 20;
        for(int i = 0; i<length ; i++){
            spriteSheetTexture->Render( x, y, &spriteClipMiddle, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
            x += 40;
        }
        spriteSheetTexture->Render( x, y, &spriteClipRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        this->word.Render(gRenderer, true);
    }
    }/*
    int x = center.x - wordWidth/2 - 20;
    int y = center.y - 30;
    spriteSheetTexture->Render( x, y, &spriteClipLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    x += 20;
    for(int i = 0; i<length ; i++){
        spriteSheetTexture->Render( x, y, &spriteClipMiddle, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        x += 40;
    }
    spriteSheetTexture->Render( x, y, &spriteClipRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    this->word.Render(gRenderer, true);
}*/
void Button::shiftOriginToCenter(){
    int length = this->word.length;
    int wordWidth = length*40;
    this->center.y += 30;
    this->center.x += (wordWidth/2)+20;
    word.x = this->center.x+20;
    word.y = this->center.y;
}
bool Button::pointLiesInBounds(int x, int y){
    int length = this->word.length;
    int wordWidth_2 = length*20;
    bool isInXRange = x > center.x-wordWidth_2-20 && x < center.x+wordWidth_2+20;
    bool isInYRange = y > center.y-30 && y < center.y+30;
    return isInXRange && isInYRange;
}
void Button::setIsClicked(bool flag){
    isClicked = flag;
}
