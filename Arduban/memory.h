#ifndef MEMORY_H
#define MEMORY_H

#include "globals.h"

// Initializes EEPROM to known values
void initEEPROM();

// Resets all levels back to incomplete
void resetLevels();

// Sets the level that they are currently working on
void setLevel(uint8_t level);

// Gets the level they last worked on
uint8_t getLevel();

// Sets the number of moves for the given level if it is lower than the amount
// already set
void setMoves(uint8_t level, uint16_t moves);

// Gets the number of moves to solve this level
uint16_t getMoves(uint8_t level);

// Determines if the given level is solved or not
bool isLevelSolved(uint8_t level);

#endif