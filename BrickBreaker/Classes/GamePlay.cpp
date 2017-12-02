#include "GamePlay.h"
#include "Bat.h"
#include "NormalBall.h"
#include "Board.h"
#include<string>
#include "Pop-Up.h"

#include"PowerUps.h"
#include<string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "windows.h"
#include "FireBall.h"
#include "ThroughBall.h"
#include "NormalFire.h"
#include "MissileFire.h"
#include <SDL_mixer.h>
#include <SDL.h>
#include <sstream>

Bat* Bat::instance = NULL;
GamePlay::GamePlay(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    loadMedia();
    holdball = false;
    blast = false;
    firemake = false;
    shoot = false;
    MisActivate = false;
    FireActivate = false;
    ThroughActivate = false;
    NormalActivate = false;
    IspeedActivate = false;
    dspeedActivate = false;
    BigbActivate = false;
    SmallbActivate = false;
    mismake = false;
    this->side1.h=650;
    this->side1.w=5;
    this->side1.x=0;
    this->side1.y=0;

    this->side2.h=5;
    this->side2.w=1000;
    this->side2.x=0;
    this->side2.y=0;

    this->side3.h=650;
    this->side3.w=5;
    this->side3.x=1000-5;
    this->side3.y=0;
    popup = NULL;
    Bat::GetInstance();
    Bat::GetInstance()->SetValue(&batBallSpriteSheet, (float)SCREEN_WIDTH/2, 630);
    //bat = new Bat(&batBallSpriteSheet, (float)SCREEN_WIDTH/2, 630);
    ball = new NormalBall(&batBallSpriteSheet, Bat::GetInstance()->x, Bat::GetInstance()->y-24);
    Missile  = new MissileFire(&batBallSpriteSheet, Bat::GetInstance()->x,Bat::GetInstance()->y-24);


    /*
    surface = IMG_Load("images/side.png");
    sidetexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    */

    srand(time(0));

    x = 16;
    y = 0;
    width = 768;
    height = 600;

    CreateLevel(4);
}



GamePlay::~GamePlay(){
    //Free all images loaded
}






void GamePlay::show(long int frame)
{


    backgroundSprite.Render(0,0,0,0.0,NULL, SDL_FLIP_NONE, renderer);
    SDL_SetRenderDrawColor( renderer,100,100,100,255);
    SDL_RenderFillRect(renderer,&(this->side1));
    SDL_RenderFillRect(renderer,&(this->side2));
    SDL_RenderFillRect(renderer,&(this->side3));
    if (BigbActivate)
    {
        Bat::GetInstance()->Render2(renderer);
        Bat::GetInstance()->width = Bat::GetInstance()->bigwidth;
    }
    else if (SmallbActivate)
    {
       Bat::GetInstance()->Render3(renderer);
       Bat::GetInstance()->width = Bat::GetInstance()->smallwidth;
    }
    else
    Bat::GetInstance()->Render(renderer);

    ball->Render(frame,renderer);
    ball->Move();
    board->Display(renderer);
    if(ball->shouldMove){
        CollisionInfo info = board->detectCollisionWithBricks(Point(ball->x - ball->width/2, ball->y - ball->height/2), ball->type, Point(ball->width, ball->height));
        ball->didCollide(info);
        if(info.directionType != NULL && info.objectType == CollisionObjectBreakableBrickType && info.brick && rand()%100<60){
                //cout<<"checkingpoweruprenderer"<<endl;
                power = new PowerUps(&PowerSpriteSheet, ball->x, ball->y);
                q.Enqueue(power);
        }
    }
q.Render(frame,renderer);
q.Move();


    if (mismake)
    {
        fire =  new MissileFire(&batBallSpriteSheet, Bat::GetInstance()->x, Bat::GetInstance()->y-23);
        MisActivate = true;

    }






    if (frame%10 ==0 && count<10 && firemake )
    {
        fire=new NormalFire(&batBallSpriteSheet, Bat::GetInstance()->x, Bat::GetInstance()->y-23);
        q.Enqueue(fire);
        count++;
        blast = true;
    }

    if (mismake)
    {
        fire = new MissileFire(&batBallSpriteSheet,Bat::GetInstance()->x, Bat::GetInstance()->y-23);
        MisActivate = true;

    }
    if (MisActivate)
    {

        fire->Render(frame,renderer);
        fire->Move();

    }


    if(blast )
    {
        q.Render(frame,renderer);
        q.Move();
    }

    if (MisActivate)
    {
        mismake = false;
        fire->Render(frame,renderer);
        fire->Move();
    }

    if(IspeedActivate)
    {
        ball->BALL_SPEED = 15;
    }
    if (dspeedActivate)
    {
        ball->BALL_SPEED = 5;

    }

    if(!isBallAlive(ball)){
        q.Clean();
        delete ball;
        loadMedia();
        blast = false;
        shoot = false;
        mball = false;
        MisActivate =false;
        FireActivate = false;
        ThroughActivate = false;
        NormalActivate = false;
        IspeedActivate = false;
        dspeedActivate = false;
        BigbActivate = false;
        SmallbActivate = false;
        mismake = false;
        firemake = false;
        ball = new NormalBall(&batBallSpriteSheet, Bat::GetInstance()->x,Bat::GetInstance()->y-24);
        Bat::GetInstance()->width = Bat::GetInstance()->normalwidth;
    }
    if (NormalActivate)
    {
         int speedx = ball->dirx;
         int speedy = ball->diry;
         int x = ball->x;
         int y = ball->y;
         int sp = ball->BALL_SPEED;
         delete ball;
         ball = new NormalBall(&batBallSpriteSheet, x,y);
         NormalActivate = false;
         ball->dirx = speedx;
         ball->diry = speedy;
         ball->BALL_SPEED = sp;
    }
    if (FireActivate)
    {

         int speedx = ball->dirx;
         int sp = ball->BALL_SPEED;
         int speedy = ball->diry;
         int x = ball->x;
         int y = ball->y;
         delete ball;
         ball = new FireBall(&batBallSpriteSheet, x,y);
         FireActivate = false;
         ball->dirx = speedx;
         ball->diry = speedy;
         ball->BALL_SPEED = sp;
         ball->shouldMove = true;



    }
    if (ThroughActivate)
    {

         int speedx = ball->dirx;
         int speedy = ball->diry;
         int sp = ball->BALL_SPEED;
         int x = ball->x;
         int y = ball->y;
         bool shouldMove = ball->shouldMove;
         delete ball;
         ball = new ThroughBall(&batBallSpriteSheet, x,y);
         ThroughActivate = false;
         ball->dirx = speedx;
         ball->diry = speedy;
         ball->BALL_SPEED = sp;
         ball->shouldMove = true;




    }



    //Code for Ball-Side Collision Detection
    if (detectCollisionBetween(side2, ball) == Vertical){
//        Mix_PlayChannel(1, medium, 0);
        ball->diry *= -1;
    }
    if (detectCollisionBetween(side1, ball) == Horizontal || detectCollisionBetween(side3, ball) == Horizontal)
    {
//        Mix_PlayChannel( 1, medium, 0 );
        ball->dirx *= -1;
    }
    if(detectCollisionBetween(Bat::GetInstance(), power)==true)
    {

        switch(power->random)
        {
            case 1: ThroughActivate=true;
            case 2: FireActivate=true;
            case 4: IspeedActivate=true;
            case 5: dspeedActivate=true;
            case 7: BigbActivate=true;
            case 8: SmallbActivate=true;
            case 9: mismake=true;
            case 10: firemake=true;
        }

    }

    //Code for Ball-Bat Collision Detection
    if (detectCollisionBetween(Bat::GetInstance(), ball) && ball->shouldMove){
//        Mix_PlayChannel( 1, medium, 0 );
//            float ballcenterx = ball->x + ball->width / 2.0f;
//            int hitx = ballcenterx - bat->x;
//           // cout<<bat->x<<endl;
//            cout<<hitx<<endl;
//            if (hitx>0){
//                ///ball->SetDirection(1,1);

                        float ballcenterx = ball->x + ball->width / 2.0f;
                        int hitx = ballcenterx - Bat::GetInstance()->x-12;

                        //cout<<hitx<<endl;
                        //ball->SetDirection(-1,1);

                        if (hitx>0 && hitx<15)
                            {
                                if (holdball)
                                {
                                    ball->shouldMove = false;
                                }

                                ball->SetDirection(0.5,-1);
                            }
                        else if (hitx>15 && hitx<30)
                            {
                                if (holdball)
                                {
                                    ball->shouldMove = false;
                                }
                                ball->SetDirection(1,-1);
                            }
                        else if (hitx>30 && hitx<45)
                            {
                                if (holdball)
                                {
                                    ball->shouldMove = false;
                                }
                                ball->SetDirection(1.5,-1);
                            }
                        else if (hitx>45)
                            {


                                ball->SetDirection(2,-1);
                            }
                        else if (hitx<0 && hitx>-15)
                                {
                                    ball->SetDirection(-0.5,-1);
                                }
                        else if (hitx<-15 && hitx>-30)
                            {
                                if (holdball)
                                {
                                    ball->shouldMove = false;
                                }
                                ball->SetDirection(-1,-1);
                            }
                        else if (hitx<-30 && hitx>-45)
                            {
                                if (holdball)
                                {
                                    ball->shouldMove = false;
                                }
                                ball->SetDirection(-1.5,-1);
                            }
                        else if (hitx<-45)
                            {


                                ball->SetDirection(-2,-1);
                            }
                        else
                            {
                                if (holdball)
                                {
                                    ball->shouldMove = false;
                                }
                                ball->diry*=-1;
                            }
//            }
//            else if (hitx<0){
//                //ball->SetDirection(-1,1);
//                ball->diry *= -1;
//            }
//            else if (hitx==0){
//                //ball->SetDirection(0,1);
//                ball->diry *= -1;
//            }

    }
    if(popup){
        popup->show();
    }
}


void GamePlay::CreateLevel(int LevelNumber) {
    board = new Board(x, y, width, height, renderer);

    std::string content;
    std::stringstream ss;
    ss << LevelNumber;
    std::string str = ss.str();

    std::string filename = "levels/" + str + ".txt";

	//opening file
    std::ifstream readfile;
    readfile.open(filename.c_str());
    int j = 0;
    while (getline(readfile, content))
    {
        for(int i=0; i<content.length(); i++)
        {
            if(i==BOARD_WIDTH)
            {
                break;
            }
            if(content[i]=='0')
            {
                int bricktype = 0;
                //cout<<bricktype<<endl;
                Brick* brick = new Brick;
                brick->type=rand()%3;
                brick->breaktype=bricktype;
                brick->state = true;
                //cout<<brick->breaktype<<endl;
                board->Enqueue(brick, i, j);
            }
            if(content[i]=='1')
            {
                int bricktype = 1;
                //cout<<bricktype<<endl;
                Brick* brick = new Brick;
                brick->type=rand()%3;
                brick->breaktype=bricktype;
                brick->state = true;
                //cout<<brick->breaktype<<endl;
                board->Enqueue(brick, i, j);
            }
            if(content[i]=='2')
            {
                int bricktype = 2;
                //cout<<bricktype<<endl;
                Brick* brick = new Brick;
                brick->type=rand()%3;
                brick->breaktype=bricktype;
                brick->state = true;
                //cout<<brick->breaktype<<endl;
                board->Enqueue(brick, i, j);
            }

            if(content[i]=='3')
            {
                int bricktype = 3;
                //cout<<bricktype<<endl;
                Brick* brick = new Brick;
                brick->type=3;
                brick->breaktype=bricktype;
                brick->state = true;
                //cout<<brick->breaktype<<endl;
                board->Enqueue(brick, i, j);
            }

            if(i==content.length()-1 && j<=BOARD_HEIGHT)
            {
                j++;

            }
        }
        if(j > BOARD_HEIGHT){
            break;
        }
    }
}
void GamePlay::click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer){
    if(popup){
        popup->click(x,y,eventType,selfPointer, &popup);
        return;
    }
    if(eventType == RightClickDown){
            std::cout<<"Pop-Up Button Down"<<std::endl;
    }else if(eventType == RightClickUp){
            std::cout<<"Pop-Up Button Up"<<std::endl;
            popup = new Pop_Up(this->renderer);
    }
}

void GamePlay::keyboardEvent(const Uint8* event, ScreenManager** selfPointer){
    if(event[ SDL_SCANCODE_SPACE ]){
        ball->shouldMove = true;
    }
    if(event[ SDL_SCANCODE_RIGHT ]){
        if(Bat::GetInstance()->x+Bat::GetInstance()->width/2>=this->side3.x || !ball->shouldMove){return;}
        Bat::GetInstance()->Move(RIGHT);
    }
    if(event[ SDL_SCANCODE_LEFT ]){

        if (Bat::GetInstance()->x-Bat::GetInstance()->width/2<=this->side1.x+this->side1.w || !ball->shouldMove){return;}
        Bat::GetInstance()->Move(LEFT);
    }
    if(event[ SDL_SCANCODE_DOWN ]){
        FireActivate = true;
    }
    if(event[ SDL_SCANCODE_UP ]){
        ThroughActivate = true;
    }
    if(event[ SDL_SCANCODE_1 ]){
        NormalActivate = true;
    }
    if(event[ SDL_SCANCODE_Z ]){
        IspeedActivate = true;
    }
    if(event[ SDL_SCANCODE_X ]){
        dspeedActivate = true;
    }
    if(event[ SDL_SCANCODE_C ]){
        firemake= true;
    }
    if(event[ SDL_SCANCODE_V ]){
        mismake= true;
    }
    if(event[ SDL_SCANCODE_B ]){
        BigbActivate = true;
    }
    if(event[ SDL_SCANCODE_N ]){
        SmallbActivate = true;
    }
    if(event[ SDL_SCANCODE_S ]){
        holdball = true;
    }
    if(popup){
        popup->keyboardEvent(event,selfPointer, &popup);
        return;
    }
}

bool GamePlay::loadMedia(){
    bool success = true;
    if( !backgroundSprite.LoadFromFile( "Images/bgimage.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !batBallSpriteSheet.LoadFromFile( "Images/finalsprites.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
	if( !PowerSpriteSheet.LoadFromFile( "Images/powerups.png", renderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
        return false;
	}
//	gScratch = Mix_LoadWAV( "sounds/high.wav" );
//	if( gScratch == NULL )
//	{
//		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//		success = false;
//	}
//	medium = Mix_LoadWAV( "sounds/medium.wav" );
//	if( medium == NULL )
//	{
//		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//		success = false;
//	}
	return true;
}
bool GamePlay::detectCollisionBetween(Bat* bat, Ball* ball){
    bool isInXRange = (ball->x+(ball->width) >= bat->x-(bat->width/2)) && (ball->x-(ball->width/2)) <= (bat->x + (bat->width/2));
    float batOriginY = bat->y - bat->height/2;
    float ballMaxY = ball->y + ball->height/2;
    return isInXRange && ballMaxY-batOriginY <= 3 && ballMaxY-batOriginY > -1;
}

bool GamePlay::detectCollisionBetween(Bat* bat, PowerUps* powerup){
    bool isInXRange = (powerup->x+(powerup->width) >= bat->x-(bat->width/2)) && (powerup->x-(ball->width/2)) <= (bat->x + (bat->width/2));
    float batOriginY = bat->y - bat->height/2;
    float ballMaxY = powerup->y + powerup->height/2;
    return isInXRange && ballMaxY-batOriginY <= 3 && ballMaxY-batOriginY > -1;
}

CollisionType GamePlay::detectCollisionBetween(const SDL_Rect& wall, Ball* ball){
    //this means the wall is horizontal
    if(wall.w > wall.h){
        if(ball->y-ball->height/2<=wall.y+wall.h){
            return Vertical;
        }
        return None;
    }
    //this means the wall is at the left side of the level.
    if(wall.x-5 < 0){
        if(ball->x-(ball->width/2) <= wall.w){
            return Horizontal;
        }
        return None;
    }
    //if the code reaches here, this means the wall is longitudinal and is at the right side.
    if(ball->x+(ball->width/2) >= wall.x){
        return Horizontal;
    }
    return None;
}

CollisionType GamePlay::detectCollisionBetween(Brick* brick, Ball* ball){
    return None;
}
bool GamePlay::isBallAlive(Ball* ball){
    return ball->y-ball->height<=SCREEN_HEIGHT;
}
