#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Classes/LTexture.h"
#include "Classes/Ball.h"
#include "Classes/Bat.h"
#include "Classes/Board.h"
#include "Classes/NormalBall.h"
#include "Classes/GamePlay.h"


//Pre defined screen width and height
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 650;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gSpriteSheetTexture;
LTexture tSpriteSheetTexture;
LTexture lSpriteSheetTexture;
LTexture xSpriteSheetTexture;
bool init();
bool loadMedia();
void close();
bool checkCollision( SDL_Rect , SDL_Rect  );
bool asd = false;

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;                      //Main loop flag

			SDL_Event e;                            //Event handler

			long int frame = 0;                     //Current animation frame

			/* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            int random =0;

            Bat* bat = new Bat(&gSpriteSheetTexture, SCREEN_WIDTH/2, 630);
            NormalBall* ball = new NormalBall(&gSpriteSheetTexture, bat->x,bat->y-23);
            Board* board = new Board(gRenderer);
			board->CreateLevel();
            bool shoot = false;
			while( !quit )                          //While application is running
			{
//			    if(frame%20 == 0)
//                {
//                    random = rand() % SCREEN_WIDTH;
//                    Ep=new Enemy(&gSpriteSheetTexture,random,0);
//
//                    q.Enqueue(Ep);
//
//                }

				while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );




                    if(currentKeyStates[ SDL_SCANCODE_SPACE ])
                    {

                       shoot = true;
                    }
				}
				const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
				if(currentKeyStates[ SDL_SCANCODE_RIGHT ])

                {
//                        if (bat->Collides(side2) ){
//
//                        }
//                        else if ( ball->x ==bat->x && ball->y ==bat->y-23 ){
//
//                        }
//                        else{
                            bat->Move(RIGHT);

                }

                if(currentKeyStates[ SDL_SCANCODE_LEFT ])
                {

//                        if (bat->Collides(side1) ){}
//                        else if ( ball->x ==bat->x&& ball->y ==bat->y-23 ){}
//                        else {
                                bat->Move(LEFT);
                }
				SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
				SDL_RenderClear( gRenderer );
				xSpriteSheetTexture.Render(0, 0, 0, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
                bat->Render(frame, gRenderer);
                ball->Render(frame,gRenderer);
                board->Render(0.56f);
                if (shoot)
                    {
                        ball->Move(1,-1);
                    }
//                if (ball->y<side3->y)
//                    {
//                        ball->y = side3->y;
//                        ball->diry *= -1;
//                    }
//                if (ball->x+ball->width<=side1->x)
//                    {
//                        ball->x = side1->x;
//                        ball->dirx *= -1;
//                    }
//                else if(ball->x-ball->width>=side2->x+side2->width)
//                    {
//
//                        ball->x = side2->x + side2->width - ball->width;
//                        ball->dirx *= -1;
//                    }
//                if (!ball->Collides(side3))
//                {
//                    ball->SetDirection(1,-1);
//                }
//
//
                if (ball->Collide2(bat))
                    {
                        float ballcenterx = ball->x + ball->width / 2.0f;
                        int hitx = ballcenterx - bat->x;
                        if (hitx>0)
                            {
                                ball->SetDirection(-1,1);
                            }
                        else if (hitx<0)
                            {
                                ball->SetDirection(1,1);
                            }
                        else if (hitx==0)
                            {
                                ball->SetDirection(0,1);
                            }

                    }

    //                    ball->y = bat->y-24;
    //                   // ball->x =  bat->x;
    //                    ball->diry*=-1;
    //                    ball->dirx*=1;

//                 if (ball->Collidesleft(side1))
//                 {
////                        ball->x = side1->x;
////                        ball->dirx *= -1;
//                     //ball->SetDirection(-1,-1);
//                 }
//                 if (ball->Collidesright(side2))
//                 {
//
////                     ball->x = side2->x + side2->width - ball->width;
////                     ball->dirx *= -1;
//                 }


//                cout<<ball->y<<endl;







				SDL_RenderPresent( gRenderer );     //Update screen

				++frame;


			}
			delete bat;
			delete ball;
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()

{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/finalsprites.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !tSpriteSheetTexture.LoadFromFile( "Images/final side 1 n 2.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !lSpriteSheetTexture.LoadFromFile( "Images/side 3 final.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !xSpriteSheetTexture.LoadFromFile( "Images/bgimage.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}


	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
