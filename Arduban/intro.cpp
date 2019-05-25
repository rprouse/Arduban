#include "intro.h"
#include "images.h"
#include "memory.h"

void gameIntro()
{
    sprites.drawSelfMasked(8, 6, Arduban, 0);
    sprites.drawSelfMasked(8, 35, ManAndBox, 0);

    font4x6.setCursor(77, 40);
    font4x6.print(F("Level "));
    font4x6.print(level);

    font4x6.setCursor(83, 48);
    uint16_t moves = getMoves(level);
    if(moves == 0xFFFF)
    {
        font4x6.print(F("Unsolved"));
    }
    else
    {
        font4x6.print(moves);
        font4x6.print(F(" moves"));
    }

    if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_LEVEL_INIT;
    else if(arduboy.justPressed(B_BUTTON))
        gameState = STATE_SETTINGS;
    else if(arduboy.justPressed(UP_BUTTON) && level > 1)
        level--;
    else if(arduboy.justPressed(DOWN_BUTTON) && level < max_levels)
        level++;
}