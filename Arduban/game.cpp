#include "game.h"
#include "levels.h"

// The current board/level we are playing
char board[ROWS][COLUMNS];

// Player column and row
int8_t pr = 0;
int8_t pc = 0;

void move(int8_t x, int8_t y)
{
    int8_t r = pr + y;
    int8_t c = pc + x;

    // Off the screen?
    if(r == -1 || r == ROWS || c == -1 || c == COLUMNS)
        return;

    switch (board[r][c])
    {
    case WALL:
        return;
    case BOX:
    case BOX_ON_GOAL:
        // Need to look one square further then push box
        break;
    case FLOOR:
        // Simple move
        board[pr][pc] = board[pr][pc] == PLAYER_ON_GOAL ? GOAL : FLOOR;
        board[r][c] = PLAYER;
        pr = r;
        pc = c;
        break;
    case GOAL:
        board[pr][pc] = board[pr][pc] == PLAYER_ON_GOAL ? GOAL : FLOOR;
        board[r][c] = PLAYER_ON_GOAL;
        pr = r;
        pc = c;
        // Simple move
    default:
        break;
    }
}

void move()
{
    if(arduboy.justPressed(UP_BUTTON))
        move(0, -1);
    else if(arduboy.justPressed(DOWN_BUTTON))
        move(0, 1);
    else if(arduboy.justPressed(RIGHT_BUTTON))
        move(1, 0);
    else if(arduboy.justPressed(LEFT_BUTTON))
        move(-1, 0);
    else if(arduboy.justPressed(A_BUTTON))
        gameState = STATE_GAME_OVER;
}

void drawBoard()
{
    for(int8_t r = 0; r < ROWS; r++)
    {
        for(int8_t c = 0; c < COLUMNS; c++)
        {
            arduboy.setCursor(c * (WIDTH / COLUMNS), r * (HEIGHT / ROWS));
            arduboy.print(board[r][c]);
        }
    }
}

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
    for(int8_t r = 0; r < ROWS; r++)
    {
        for(int8_t c = 0; c < COLUMNS; c++)
        {
            board[r][c] = pgm_read_byte(&levels[level-1][r][c]);
        }
    }
    findPlayer();
    gameState = STATE_GAME_PLAY;
}

void gamePlay()
{
    move();
    drawBoard();
}