#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Bat.h"
#include "Ball.h"
#include "Board.h"
#include "LTexture.h"
#include "Statics.h"
#include "Board.h"
#include "Object.h"
#include "ScreenManager.h"


// Define the dimensions of the board and bricks


#include <typeinfo>



class GamePlay : public ScreenManager
{
    public:
        GamePlay();
        GamePlay(SDL_Renderer* gRenderer);
        void show();
        void click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** selfPointer);
        ~GamePlay();

        void CreateLevel();
        Board* board;

        float x, y, width, height;

        Bat* bat;
        Ball* ball;

        SDL_Rect side1;
        SDL_Rect side2;
        SDL_Rect side3;

    private:
        SDL_Renderer* renderer;
        bool loadMedia();
        LTexture brickSpriteSheet;
};

#endif // GAMEPLAY_H
