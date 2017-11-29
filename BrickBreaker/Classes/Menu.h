#ifndef MENU_H
#define MENU_H

#include "ScreenManager.h"
#include "Button.h"
#include "Statics.h"


class Menu : public ScreenManager
{
    public:
        Menu();
        Menu(SDL_Renderer* renderer);
        void show(long int frame);
        void click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** selfPointer);
        ~Menu();
        LTexture splashSpriteSheetTexture;


    private:
        Button newGame;
        Button loadGame;
        Button exitGame;
        LTexture gSpriteSheetTexture;
        LTexture backSpriteSheetTexture;
        bool loadMedia();


};
#endif // MENU_H
