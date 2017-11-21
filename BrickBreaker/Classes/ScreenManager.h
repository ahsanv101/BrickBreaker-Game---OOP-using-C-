#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SDL.h>
#include <SDL_image.h>

class ScreenManager
{
    public:
        ScreenManager();
        ScreenManager(SDL_Texture* backgroundImage);
        virtual void show(SDL_Renderer*) = 0;
        virtual void click(int x, int y, ScreenManager** selfPointer) = 0;
        virtual void keyboardClick(const Uint8 event, ScreenManager** selfPointer) = 0;
        virtual ~ScreenManager();

    protected:
        SDL_Texture* backgroundImage;

};

#endif // SCREENMANAGER_H
