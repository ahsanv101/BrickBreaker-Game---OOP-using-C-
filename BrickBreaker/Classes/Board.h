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
#include <ostream>


class Board
{
private:
    Node* head;
    Node* tail;
    SDL_Renderer* renderer;
    bool loadMedia();
    LTexture brickSpriteSheet;
    CollisionType detectCollisionWithBrick(Point objectPos, Point objectSize, Node* brickNode);

public:
    Board();
    ~Board();
    Board(float x, float y, float width, float height, SDL_Renderer* renderer);
    void Enqueue(Brick* brick, int column, int row);
    void Display(SDL_Renderer* gRenderer);
    CollisionInfo detectCollisionWithBricks(Point ballPos, BallType ballType, Point ballSize);
    bool detectCollisionWithBricks(Point firePos, FireType fireType, Point fireSize);
    float x,y,width,height;
    Node* getHead();
};
