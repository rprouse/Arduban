#include "globals.h"
#include "levels.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
Sprites sprites;

byte gameState = STATE_GAME_INTRO;

uint8_t max_levels = sizeof(levels) / sizeof(char*);
uint8_t level = 1;
uint8_t frame = 0;

#if DEBUG
// Helper function to dump a byte as a hex value to Serial
void printHex(byte b)
{
    Serial.print(b < 0x10 ? "0x0" : "0x");
    Serial.print(b, HEX);
}

// Helper routine to dump a byte array as hex values to Serial.
void printHex(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    printHex(buffer[i]);
  }
}
#endif