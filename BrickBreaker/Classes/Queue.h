#pragma once
#include"Node.h"
#include"Brick.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

#define BOARD_WIDTH 12
#define BOARD_HEIGHT 8
#define BOARD_BRWIDTH 63
#define BOARD_BRHEIGHT 31

class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(Brick*, int, int);
    //Brick* Dequeue();
    //int DequeueAt(int); //Make it work
    //void Display();
    Node* returnhead();
};
