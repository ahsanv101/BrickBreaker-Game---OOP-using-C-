#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Bat.h"
#include "Ball.h"
#include "Board.h"
#include "LTexture.h"


#include"Queue.h"
#include"Object.h"


// Define the dimensions of the board and bricks
#define BOARD_WIDTH 12
#define BOARD_HEIGHT 8
#define BOARD_BRWIDTH 63
#define BOARD_BRHEIGHT 31

#include <typeinfo>



class GamePlay
{
        public:


        void Update(float delta);

        void CreateLevel();

        float brickoffsetx, brickoffsety;

        // Define the two-dimensional array of bricks
        //Brick bricks[BOARD_WIDTH][BOARD_HEIGHT];
        Queue brickstorender;


        SDL_Texture* bricktexture;
        SDL_Texture* sidetexture;




        float x, y , width, height;
        const int SCREEN_WIDTH = 1000;
        const int SCREEN_HEIGHT = 650;
        const int speed = 5;
        Bat* bat;
        SDL_Rect dstrect;
        SDL_Rect srcrect;
        Ball* ball;

        GamePlay();
        GamePlay(SDL_Renderer* gRenderer);

        ~GamePlay();
        void Render(SDL_Renderer* renderer, float delta);
        SDL_Rect side1;
        SDL_Rect side2;
        SDL_Rect side3;


    private:
};

#endif // GAMEPLAY_H
