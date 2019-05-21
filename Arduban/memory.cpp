#include "memory.h"

// First 16 bytes are reserved for the Arduboy, second 16 bytes are reserved
// for game specific settings then levels are stored starting 32 bytes in.
#define EEPROM_ID1          EEPROM_STORAGE_SPACE_START
#define EEPROM_ID2          EEPROM_STORAGE_SPACE_START + 1
#define EEPROM_ID3          EEPROM_STORAGE_SPACE_START + 2
#define EEPROM_LAST_LEVEL   EEPROM_STORAGE_SPACE_START + 3

#define EEPROM_LEVEL_START  EEPROM_STORAGE_SPACE_START + 16

void initEEPROM()
{
    unsigned char c1 = EEPROM.read(EEPROM_ID1);
    unsigned char c2 = EEPROM.read(EEPROM_ID2);
    unsigned char c3 = EEPROM.read(EEPROM_ID3);

    // check the first three chars, are they ARB to identify the game? if
    // not reset the EEPROM memory.
    if(c1 != 'A' || c2 != 'R' || c3 != 'B')
    {
        // Reset the tag
        EEPROM.update(EEPROM_ID1, 'A');
        EEPROM.update(EEPROM_ID2, 'R');
        EEPROM.update(EEPROM_ID3, 'B');

        setLevel(1);

        resetLevels();
    }
}

void resetLevels()
{
    // Erase the levels
    for(uint16_t addr = EEPROM_LEVEL_START; addr < E2END; addr++)
    {
        EEPROM.update(addr, 0xFF);
    }
}

void setLevel(uint8_t level)
{
    EEPROM.update(EEPROM_LAST_LEVEL, level);
}

uint8_t getLevel()
{
    return (uint8_t)EEPROM.read(EEPROM_LAST_LEVEL);
}

void setMoves(uint8_t level, uint16_t moves)
{
    uint16_t prev = getMoves(level);
    if(prev == 0xFFFF || moves < prev)
    {
        uint16_t addr = EEPROM_LEVEL_START + level * 2;
        EEPROM.update(addr, highByte(moves));
        EEPROM.update(addr + 1, lowByte(moves));
    }
}

uint16_t getMoves(uint8_t level)
{
    uint16_t addr = EEPROM_LEVEL_START + level * 2;
    byte high = EEPROM.read(addr);
    byte low = EEPROM.read(addr+1);
    return (uint16_t)high << 8 | low;
}

bool isLevelSolved(uint8_t level)
{
    return getMoves(level) == 0xFFFF;
}