#include "intro.h"

void gameIntro()
{
    arduboy.setCursor(0, 10);
    arduboy.println("Welcome to the Game");
    arduboy.println("Press A to START");
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_LEVEL_INIT;
}