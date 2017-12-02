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
#include "Fire.h"
#include "q.h"
#include <SDL_mixer.h>
#include "Pop-Up.h"


#include <typeinfo>



class GamePlay : public ScreenManager
{
    public:
        GamePlay();
        GamePlay(SDL_Renderer* gRenderer);
        GamePlay(SDL_Renderer* gRenderer, Bat* bat, Ball* ball, Board* board, LTexture* backTexture, LTexture* batBallTexture);
        void show(long int frame);
        void click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** selfPointer);
        ~GamePlay();

        void CreateLevel();
        Board* getBoard() const;
        Ball* getBall() const;
        Bat* getBat() const;
        SDL_Rect getBoardBounds();
        void setBoard(Board* board);

    private:
        SDL_Renderer* renderer;
        bool loadMedia();

        LTexture* backgroundSprite;
        LTexture* batBallSpriteSheet;
        bool shoot;

        Board* board;
        Bat* bat;
        Ball* ball;
        Fire* fire;
        Fire* Missile;
        Queue q;
        int count = 0;

        SDL_Rect side1;
        SDL_Rect side2;
        SDL_Rect side3;

        Pop_Up* popup;

        float x, y, width, height;

        //collision detection functions
        bool detectCollisionBetween(Bat*, Ball*);
        CollisionType detectCollisionBetween(const SDL_Rect& wall, Ball*);
        CollisionType detectCollisionWithSides(Ball*);
        bool isBallAlive(Ball*);

        Mix_Chunk *gScratch = NULL;
        Mix_Chunk *medium = NULL;
        bool blast;
        bool MisActivate;
        bool FireActivate;
        bool ThroughActivate;
        bool NormalActivate;
        bool IspeedActivate;
        bool dspeedActivate;
        bool BigbActivate;
        bool SmallbActivate;
};

#endif // GAMEPLAY_H
