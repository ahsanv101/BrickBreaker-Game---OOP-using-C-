#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
    this->backgroundImage = NULL;
}
ScreenManager::ScreenManager(SDL_Texture* backgroundImage)
{
    this->backgroundImage = backgroundImage;
}

ScreenManager::~ScreenManager()
{
    //dtor
}
