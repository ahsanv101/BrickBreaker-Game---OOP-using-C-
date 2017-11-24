#pragma once
#include"Node.h"
#include"Brick.h"
#include"LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>


class Board
{
private:
    Node* head;
    Node* tail;
    SDL_Renderer* renderer;
    bool loadMedia();
    LTexture brickSpriteSheet;

public:
    Board();
    ~Board();
    Board(float x, float y, float width, float height, SDL_Renderer* renderer);
    void Enqueue(Brick* brick, int column, int row);
    void Display(SDL_Renderer* gRenderer);
    float x,y,width,height;
};
