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

#endif