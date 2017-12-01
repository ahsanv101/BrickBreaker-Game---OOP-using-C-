#include"Board.h"
#include"Statics.h"
#include"Brick.h"
#include"Point.h"
#include<SDL.h>
#include<iostream>
#include<ostream>

using namespace std;

Board::Board()
{
    head = NULL;
    tail = NULL;
}
Board::Board(float x, float y, float width, float height, SDL_Renderer* renderer)
{
    head = NULL;
    tail = NULL;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->renderer = renderer;
    if(!loadMedia()){
        std::cout<<"Error loading media in Board class";
    }
}

Board::~Board()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        //cout<<"Deallocating value: "<<temp->data<<endl;
        delete temp;
    }
}

void Board::Enqueue(Brick* brick, int column, int row)
{
    if(head == NULL)
    {
        head = new Node;
        head->brick = brick;
        head->position = column;
        head->y = row;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->position = column;
        tail->next->y = row;
        tail->next->brick = brick;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

/*

Brick* Board::Dequeue()
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

void Board::Display(SDL_Renderer* gRenderer)
{
    // Render bricks
    Node* temp = head;
    while(temp!=NULL){

        Brick brick = *temp->brick;
        int i= temp->position%12;
        int j = temp->y;

        temp = temp->next;

        // Check if the brick exists
        if(!brick.state)
        {
            continue;
        }


        SDL_Rect srcrect;
        srcrect.x = 9 + (brick.type * BOARD_BRWIDTH);
        srcrect.y = 61 + ((brick.breaktype) * BOARD_BRHEIGHT);
        srcrect.w = BOARD_BRWIDTH;
        srcrect.h = BOARD_BRHEIGHT;

        SDL_Rect dstrect;
        dstrect.x = x + (i * BOARD_BRWIDTH);
        dstrect.y = y + (j * BOARD_BRHEIGHT);
        dstrect.w = BOARD_BRWIDTH;
        dstrect.h = BOARD_BRHEIGHT;

        brickSpriteSheet.Render(dstrect.x,dstrect.y,&srcrect,0.0,NULL,SDL_FLIP_NONE,gRenderer);
    }
}
bool Board::loadMedia()
{
	//Load sprite sheet texture
	if( !brickSpriteSheet.LoadFromFile( "Images/finalsprites.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	return true;
}
CollisionInfo Board::detectCollisionWithBricks(Point ballPos, BallType ballType, Point ballSize){
    Node* temp = head;
    CollisionInfo c;
    while(temp!=NULL){
        CollisionType type = detectCollisionWithBrick(ballPos, ballSize, temp);
        if(type != None){
            temp->brick->state = false;
            c.directionType = type;
            c.objectType = temp->brick->type == 3 ? CollisionObjectUnbreakableBrickType : CollisionObjectBreakableBrickType;
            return c;
        }
        temp = temp->next;
    }
    c.directionType = None;
    c.objectType = CollisionObjectBreakableBrickType;
    return c;
}
bool Board::detectCollisionWithBricks(Point firePos, FireType fireType, Point fireSize){
    Node* temp = head;
    while(temp!=NULL){

    }
    return false;
}
CollisionType Board::detectCollisionWithBrick(Point objectPos, Point objectSize, Node* brickNode){
    int i = brickNode->position;
    int j = brickNode->y;
    if(!brickNode->brick->state){
        return None;
    }
    Point brickPos(x + (i * BOARD_BRWIDTH), y + (j * BOARD_BRHEIGHT));
    Point brickDestPoint(brickPos.x + BOARD_BRWIDTH, brickPos.y + BOARD_BRHEIGHT);
    Point objectDestPoint(objectPos.x + objectSize.x, objectPos.y + objectSize.y);
    Point objectCenterPoint((objectPos.x + objectPos.x + objectSize.x)/2, (objectPos.y + objectPos.y + objectSize.y)/2);
    bool isInXRange = (brickPos.x <= objectPos.x && brickDestPoint.x >= objectCenterPoint.x) || (brickPos.x <= objectCenterPoint.x && brickDestPoint.x >= objectDestPoint.x);
    //Vertical Collision Detection
    if(isInXRange){
        bool didCollide = (brickPos.y > objectPos.y && brickPos.y < objectDestPoint.y) || (brickDestPoint.y > objectPos.y && brickDestPoint.y < objectDestPoint.y);
        return didCollide ? Vertical : None;
    }
    //Horizontal Collision Detection
    bool isInYRange = (brickPos.y <= objectPos.y && brickDestPoint.y >= objectCenterPoint.y) || (brickPos.y <= objectCenterPoint.y && brickDestPoint.y >= objectDestPoint.y);
    if(isInYRange){
        bool didCollide = (brickPos.x > objectPos.x && brickPos.x < objectDestPoint.x) || (brickDestPoint.x > objectPos.x && brickDestPoint.x < objectDestPoint.x);
        return didCollide ? Horizontal : None;
    }
    return None;
}
