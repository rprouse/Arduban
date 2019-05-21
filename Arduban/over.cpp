#include "over.h"

void gameOver()
{
    arduboy.setCursor(0, 10);
    arduboy.println(F("All levels complete!"));

    arduboy.setCursor(0, 50);
    arduboy.println(F("Press A - Main menu"));
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_GAME_INTRO;
}