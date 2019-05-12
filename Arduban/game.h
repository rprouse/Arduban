#ifndef GAME_H
#define GAME_H

#include "globals.h"

#define WALL            '#'
#define PLAYER          '@'
#define PLAYER_ON_GOAL  '+'
#define BOX             '$'
#define BOX_ON_GOAL     '*'
#define GOAL            '.'
#define FLOOR           ' '

void loadLevel();
void gamePlay();

#endif