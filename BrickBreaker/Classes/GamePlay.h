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
#include "PowerUps.h"

#include <typeinfo>



class GamePlay : public ScreenManager
{
    public:
        GamePlay();
        //level and lives
        GamePlay(SDL_Renderer* gRenderer, int levelNumber, int lifeCount = 3);
        GamePlay(SDL_Renderer* gRenderer, Ball* ball, Board* board, LTexture* backTexture, LTexture* batBallTexture, LTexture* buttonSprite, LTexture* fontSprite, int lifeCount= 3);
        GamePlay(SDL_Renderer* renderer, ShapeLevel levelShape, int lifeCount = 3);
        void show(long int frame);
        void click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** selfPointer); //keyboard events
        ~GamePlay();

        Board* getBoard() const;
        Ball* getBall() const;
        SDL_Rect getBoardBounds();
        void CreateLevel(int);
        int getCurrentLevel();
        void CreateLevel(ShapeLevel);
        int getLives() const;

    private:
        int lives;
        int levelNumber;
        bool isPaused;
        bool loadMedia();
        void updateLifeButton();
        void allBallOperations(node* ballNode);

        //all the spites
        LTexture* backgroundSprite;
        LTexture* batBallSpriteSheet;
        LTexture* PowerSpriteSheet;
        LTexture* buttonSprite;
        LTexture* fontSprite;
        bool shoot;

        Board* board;

        Queue q;
        int count = 0;

        SDL_Rect side1;
        SDL_Rect side2;
        SDL_Rect side3;

        Pop_Up* popup;
        Button life;

        float x, y, width, height;

        //collision detection functions
        bool detectCollisionBetween(Bat*, Ball*);
        bool detectCollisionBetween(Bat*, PowerUps*);
        CollisionType detectCollisionBetween(const SDL_Rect& wall, Ball*);
        CollisionType detectCollisionWithSides(Ball*);
        bool isBallAlive(Ball*);
        //all music
        Mix_Chunk *medium = NULL;
        Mix_Chunk *powers = NULL;
        Mix_Chunk *smash = NULL;
        Mix_Chunk *missi = NULL;
        Mix_Chunk *fir = NULL;
        //all powerups
        bool holdball;
        bool blast;
        bool mball;
        bool mismake;
        bool firemake;
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
