#pragma once
#include"node (2).h"

class Queue
{
private:
    node* head;
    node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(Fire*);
    void Clean();
    void Render(long int frame, SDL_Renderer* gRenderer);
    void Move();
};
