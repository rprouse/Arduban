#include "load.h"
#include "levels.h"
#include "memory.h"
#include "game.h"

// Finds the player in the new board
void findPlayer()
{
    for(int8_t r = 0; r < ROWS; r++)
    {
        for(int8_t c = 0; c < COLUMNS; c++)
        {
            if(board[r][c] == PLAYER || board[r][c] == PLAYER_ON_GOAL)
            {
                pr = r;
                pc = c;
                return;
            }
        }
    }
}

void loadLevel()
{
    uint8_t row = 0;
    uint8_t col = 0;
    uint8_t i = 0;
    char b;
    const __FlashStringHelper * buff = (__FlashStringHelper*)pgm_read_word(&(levels[level-1]));

    memcpy_P(&b, (PGM_P)buff, 1);
    while(b != 0x00)
    {
        i++;
        if(col >= COLUMNS)
        {
            row++;
            col = 0;
        }

        byte count = (b & 0xF0) >> 4;
        byte tile  = b & 0x0F;
        for(byte i = 0; i <= count; i++)
        {
            board[row][col++] = tile;
        }
        memcpy_P(&b, (PGM_P)buff + i, 1);
    }

    findPlayer();
    arduboy.setRGBled(0, 0, 0);
    gameState = STATE_GAME_PLAY;
    reset();

    setLevel(level);
    bestScore = getMoves(level);
}