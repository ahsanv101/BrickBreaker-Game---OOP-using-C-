

#ifndef BOARD_H_
#define BOARD_H_

#include"Queue.h"
#include"Object.h"


// Define the dimensions of the board and bricks
#define BOARD_WIDTH 12
#define BOARD_HEIGHT 8
#define BOARD_BRWIDTH 63
#define BOARD_BRHEIGHT 31

#include <typeinfo>





class Board : public Object{
public:
    Board(SDL_Renderer* renderer);
    ~Board();

    void Update(float delta);
    void Render(float delta);
    void CreateLevel();

    float brickoffsetx, brickoffsety;

    // Define the two-dimensional array of bricks
    //Brick bricks[BOARD_WIDTH][BOARD_HEIGHT];
    Queue brickstorender;

private:
    SDL_Texture* bricktexture;
    SDL_Texture* sidetexture;

};

#endif


