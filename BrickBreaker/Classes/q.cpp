#include"q.h"
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
        node* temp = head;
        head = head->next;
        //cout<<"Deallocating value: "<<temp->data<<endl;
        delete temp;
    }
}

void Queue::Enqueue(Object* unit)
{

    if(head == NULL)
    {
        head = new node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {

        tail->next = new node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Clean()
{
    while(head != NULL)
    {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Render(long int frame, SDL_Renderer* gRenderer)
{
    node* temp = head;
    while(temp!=NULL)
    {
        temp->unit->Render(frame, gRenderer);
        temp=temp->next;
    }
}

void Queue::Move()
{
    node* temp = head;
    while(temp!=NULL)
    {
        temp->unit->Move();
        temp=temp->next;
    }
}
