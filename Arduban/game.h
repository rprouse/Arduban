#ifndef GAME_H
#define GAME_H

#include "globals.h"

#define WALL            0x01    // #
#define PLAYER          0x02    // @
#define PLAYER_ON_GOAL  0x03    // +
#define BOX             0x04    // $
#define BOX_ON_GOAL     0x05    // *
#define GOAL            0x06    // .
#define FLOOR           0x07    //

void loadLevel();
void gamePlay();
void levelSolved();

#endif