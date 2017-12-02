#ifndef MENU_H
#define MENU_H

#include "ScreenManager.h"
#include "Button.h"
#include "Statics.h"
#include "Pop-Up.h"


class Menu : public ScreenManager
{
    public:
        Menu();
        Menu(SDL_Renderer* renderer);
        void show(long int frame);
        void click(int x, int y, MouseEventType eventType, ScreenManager** selfPointer);
        void keyboardEvent(const Uint8* event, ScreenManager** selfPointer);
        ~Menu();


    private:
        Button newGame;
        Button loadGame;
        Button exitGame;
        Button life;
        LTexture gSpriteSheetTexture;
        LTexture backSpriteSheetTexture;
        LTexture buttonSpriteTexture;
        bool loadMedia();
        Pop_Up* popup;


};
#endif // MENU_H
