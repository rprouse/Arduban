#include "intro.h"

void gameIntro()
{
    arduboy.setCursor(0, 10);
    arduboy.println("Welcome to Arduban");
    arduboy.println();
    arduboy.print("Level ");
    arduboy.println(level);
    arduboy.println();
    arduboy.println("Press A to START");
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_LEVEL_INIT;
    else if(arduboy.justPressed(UP_BUTTON) && level > 1)
        level--;
    else if(arduboy.justPressed(DOWN_BUTTON) && level < MAX_LEVELS)
        level++;
}