#include "over.h"

void gameOver()
{
    arduboy.setCursor(0, 10);
    arduboy.println("GAME OVER");
    arduboy.println("Press A");
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_GAME_INTRO;
}