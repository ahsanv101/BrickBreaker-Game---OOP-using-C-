#pragma once
#include<string>
#include"Character.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
//#include"Point.h"
//Character* c;
class Word
{
    public:
        Word();
        Word(LTexture* image, float x, float y, std::string a);
        SDL_Renderer* gRenderer;
        int length;
        Character* chars;
        void Render(SDL_Renderer* gRenderer, bool debug);
        std::string str;
        float x;
        float y;
        LTexture* spriteSheetTexture;
        //Character cc[5];
    private:
        //Character* c;
};

