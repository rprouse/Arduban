#include "game.h"
#include "levels.h"

// The current board/level we are playing
char board[ROWS][COLUMNS];

// Player column and row
int8_t pr = 0;
int8_t pc = 0;

bool offScreen(int8_t r, int8_t c)
{
    return (r == -1 || r == ROWS || c == -1 || c == COLUMNS);
}

void move(int8_t x, int8_t y)
{
    int8_t r = pr + y;
    int8_t c = pc + x;

    if(offScreen(r,c))
        return;

    switch (board[r][c])
    {
    case WALL:
        return;
    case FLOOR:
        board[r][c] = PLAYER;
        break;
    case GOAL:
        board[r][c] = PLAYER_ON_GOAL;
        break;
    case BOX:
    case BOX_ON_GOAL:
        // Need to look one square further then push box
        uint8_t r2 = r + y;
        uint8_t c2 = c + x;

        if(offScreen(r2,c2))
            return;

        if(board[r2][c2] == WALL || board[r2][c2] == BOX || board[r2][c2] == BOX_ON_GOAL)
            return;

        // Push the box
        board[r2][c2] = board[r2][c2] == GOAL ? BOX_ON_GOAL : BOX;
        board[r][c] = board[r][c] == BOX_ON_GOAL ? PLAYER_ON_GOAL : PLAYER;
        break;
    default:
        // This should never happen!
        break;
    }

    // Set the board based on where the player WAS
    board[pr][pc] = board[pr][pc] == PLAYER_ON_GOAL ? GOAL : FLOOR;
    pr = r;
    pc = c;
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