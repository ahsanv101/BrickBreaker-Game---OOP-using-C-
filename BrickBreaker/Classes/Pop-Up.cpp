#include "Pop-Up.h"

Pop_Up::Pop_Up()
{
    this->renderer = NULL;
}

Pop_Up::Pop_Up(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

Pop_Up::~Pop_Up()
{
    //dtor
}
