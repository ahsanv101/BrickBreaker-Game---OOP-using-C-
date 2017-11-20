#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        //cout<<"Deallocating value: "<<temp->data<<endl;
        delete temp;
    }
}

void Queue::Enqueue(Brick* bricktoadd, int pos, int ypos)
{
    if(head == NULL)
    {
        head = new Node;
        head->brick = bricktoadd;
        head->position = pos;
        head->y = ypos;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->position = pos;
        tail->next->y = ypos;
        tail->next->brick = bricktoadd;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

/*

Brick* Queue::Dequeue()
{
    int value = -1;
    if(head != NULL)
    //Brick* brick;
    {
        Brick* brick;
        Node* temp = head;
        brick = head->brick;
        head = head->next;
        if(head!=NULL)
        {
            head->prev = NULL;
        }
        return brick;
        delete temp;
    }
}
*/

/*
void Queue::Display()
{
    // Render bricks
            int j=0;
            Node* temp = this->head;
            while(temp!=NULL)
        {
            Brick brick= *temp->brick;
            int i= temp->position%12;
            j = temp->y;

            temp=temp->next;

            // Check if the brick exists
            if(!brick.state)
            {
                continue;
            }
            float brickoffsetx = 0;
            float brickoffsety = 0;

            SDL_Rect srcrect;

            srcrect.x = 9 + (brick.type) * BOARD_BRWIDTH;
            srcrect.y = 61 + ((brick.breaktype) * BOARD_BRHEIGHT);
            srcrect.w = BOARD_BRWIDTH;
            srcrect.h = BOARD_BRHEIGHT;

            SDL_Rect dstrect;
            dstrect.x = brickoffsetx + x + i * BOARD_BRWIDTH;
            dstrect.y = brickoffsety + y + j * BOARD_BRHEIGHT;
            dstrect.w = BOARD_BRWIDTH;
            dstrect.h = BOARD_BRHEIGHT;

            SDL_RenderCopy(renderer, bricktexture, &srcrect, &dstrect);
}
*/


Node* Queue::returnhead()
{
    return head;
}
