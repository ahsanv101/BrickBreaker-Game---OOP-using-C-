#pragma once
#include"Node.h"
#include"Brick.h"
#include"LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Statics.h"
#include "Point.h"


class Board
{
private:
    Node* head;
    Node* tail;
    SDL_Renderer* renderer;
    bool loadMedia();
    LTexture brickSpriteSheet;
    CollisionType detectCollisionWithBrick(Point objectPos, Brick brick);

public:
    Board();
    ~Board();
    Board(float x, float y, float width, float height, SDL_Renderer* renderer);
    void Enqueue(Brick* brick, int column, int row);
    void Display(SDL_Renderer* gRenderer);
    CollisionType detectCollisionWithBricks(Point ballPos, BallType ballType);
    CollisionType detectCollisionWithBricks(Point FirePos, FireType fireType);
    float x,y,width,height;
};
