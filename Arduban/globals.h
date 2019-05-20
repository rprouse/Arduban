#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <Arduboy2.h>
#include <ArduboyTones.h>

// For serial port debugging
#define DEBUG               0

#define STATE_GAME_INTRO    0
#define STATE_LEVEL_INIT    1
#define STATE_GAME_PLAY     2
#define STATE_LEVEL_SOLVED  3
#define STATE_GAME_OVER     4

#define COLUMNS            16
#define ROWS                8

extern Arduboy2 arduboy;
extern ArduboyTones sound;
extern Sprites sprites;
extern byte gameState;
extern uint8_t max_levels;
extern uint8_t level;
extern uint8_t frame;

// Helper function to dump a byte as a hex value to Serial
void printHex(byte b);

// Helper routine to dump a byte array as hex values to Serial.
void printHex(byte *buffer, byte bufferSize);

#endif