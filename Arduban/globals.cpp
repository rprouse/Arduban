#include "globals.h"

Arduboy2 arduboy;
Sprites sprites;

byte gameState = STATE_GAME_INTRO;

uint8_t level = 1;
uint8_t frame = 0;