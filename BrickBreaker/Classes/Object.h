#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Statics.h"


#ifndef OBJECT_H_
#define OBJECT_H_



class Object {
public:
    Object();
    Object(SDL_Renderer* renderer);
    virtual ~Object();

    float x, y, width, height;
    MovingObjectType objectType;
    //virtual void Update(float delta);
    virtual void Render(long int frame, SDL_Renderer* renderer);
    virtual void Move()=0;
    bool Collides(Object* other);
protected:
    SDL_Renderer* renderer;

};

#endif
