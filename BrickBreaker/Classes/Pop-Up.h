#ifndef POP-UP_H_INCLUDED
#define POP-UP_H_INCLUDED

#include "ScreenManager.h"
#include "Button.h"
#include "Statics.h"

class Pop_Up
{
    public:
        Pop_Up();
        Pop_Up(SDL_Renderer* renderer);
        void show();
        void click(int x, int y, MouseEventType eventType, ScreenManager** parentPointer, Pop_Up** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** parentPointer, Pop_Up** selfPointer);
        ~Pop_Up();

    private:
        Button resume;
        Button save;
        Button restart;
        Button quit;
        LTexture gSpriteSheetTexture;
        LTexture backSpriteSheetTexture;
        LTexture buttonSpriteTexture;
        SDL_Renderer* renderer;
        bool loadMedia();
};

#endif // POP-UP_H_INCLUDED
