#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <Arduboy2.h>

#define STATE_GAME_INTRO    0
#define STATE_LEVEL_INIT    1
#define STATE_GAME_PLAY     2
#define STATE_LEVEL_SOLVED  3
#define STATE_GAME_OVER     4

#define MAX_LEVELS 2

#define COLUMNS            16
#define ROWS                8

extern Arduboy2 arduboy;
extern Sprites sprites;
extern byte gameState;
extern uint8_t level;
extern uint8_t frame;

#endif