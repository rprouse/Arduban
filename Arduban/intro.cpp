#include "intro.h"
#include "memory.h"

void gameIntro()
{
    arduboy.setCursor(0, 10);
    arduboy.println(F("Arduban by Rob Prouse"));
    arduboy.println();
    arduboy.print(F("Level "));
    arduboy.println(level);
    uint16_t moves = getMoves(level);
    if(moves == 0xFFFF)
    {
        arduboy.println(F("Unsolved"));
    }
    else
    {
        arduboy.print(moves);
        arduboy.println(F(" moves"));
    }

    arduboy.setCursor(0, 50);
    arduboy.println(F("Press A - Start level"));
    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_LEVEL_INIT;
    else if(arduboy.justPressed(UP_BUTTON) && level > 1)
        level--;
    else if(arduboy.justPressed(DOWN_BUTTON) && level < max_levels)
        level++;
}