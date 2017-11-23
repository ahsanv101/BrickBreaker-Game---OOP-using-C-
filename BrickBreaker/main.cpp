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
#include "ScreenManager.h"
#include"Statics.h"
#include "Menu.h"


#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>


//Pre defined screen width and height



bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gSpriteSheetTexture;
LTexture tSpriteSheetTexture;
LTexture lSpriteSheetTexture;
LTexture xSpriteSheetTexture;

//All Screens will implement this protocol to get rendered on through main
ScreenManager* currentManager = NULL;

bool init();
bool loadMedia();
void close();
bool checkCollision( SDL_Rect , SDL_Rect  );

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
		close();
		return -1;
	}
    //Load media
    if( !loadMedia() )
    {
        printf( "Failed to load media!\n" );
        close();
        return -2;
    }
    bool quit = false;                      //Main loop flag
    SDL_Event e;                            //Event handler

    long int frame = 0;                     //Current animation frame

    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    int random =0;
    currentManager = new Menu(gRenderer);

    bool shoot = false;
    while( !quit )                          //While application is running
    {
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {
                //Get mouse position
                int x, y;
                SDL_GetMouseState( &x, &y );
                if(e.type ==  SDL_MOUSEMOTION)
                {
                    currentManager->click(x, y, MouseMotion, &currentManager);
                }else if(e.type == SDL_MOUSEBUTTONDOWN)
                {
                    if (e.button.button == SDL_BUTTON_LEFT)
                    {
                        currentManager->click(x, y, ClickDown, &currentManager);
                    }else{
                        currentManager->click(x, y, RightClickDown, &currentManager);
                    }
                }else if(e.type == SDL_MOUSEBUTTONUP)
                {
                    if (e.button.button == SDL_BUTTON_LEFT)
                    {
                        currentManager->click(x, y, ClickUp, &currentManager);
                    }else{
                        currentManager->click(x, y, RightClickUp, &currentManager);
                    }
                }
            }
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
        currentManager->keyboardClick(currentKeyStates, &currentManager);

        SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );    //Clear screen
        SDL_RenderClear( gRenderer );
        currentManager->show();
        SDL_RenderPresent( gRenderer );     //Update screen
        ++frame;
    }

//    delete ball2;
    delete bat;
    delete ball;
    close();
	return 0;
}

bool init()

{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
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
        return false;
    }
    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( gRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
        return false;
    }

	return true;
}


bool loadMedia()
{
	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/finalsprites.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture finalsprites.png!\n" );
		return false;
	}
	if( !tSpriteSheetTexture.LoadFromFile( "Images/final side 1 n 2.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture final side 1 n 2.png!\n" );
		return false;
	}
	if( !lSpriteSheetTexture.LoadFromFile( "Images/side 3 final.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture side 3 final.png!\n" );
		return false;
	}
	if( !xSpriteSheetTexture.LoadFromFile( "Images/bgimage.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture bgimage.png!\n" );
		return false;
	}
	return true;
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
