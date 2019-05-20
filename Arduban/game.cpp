#include "game.h"
#include "levels.h"
#include "images.h"

#define NOTE_LENGTH         150
#define FRAMES_TO_RESET      90
#define EXPLODE_FRAMES        6
#define MAX_UNDO            128

// The current board/level we are playing
byte board[ROWS][COLUMNS];
uint16_t moves = 0;
uint8_t reset_count = 0;
bool exploded = false;
byte undoBuffer[MAX_UNDO];
uint8_t undoCount = 0;

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
    {
        sound.tone(NOTE_C1, NOTE_LENGTH);
        return;
    }

    switch (board[r][c])
    {
    case WALL:
        return;
    case FLOOR:
        board[r][c] = PLAYER;
        sound.tone(NOTE_C3, NOTE_LENGTH);
        break;
    case GOAL:
        sound.tone(NOTE_E3, NOTE_LENGTH);
        board[r][c] = PLAYER_ON_GOAL;
        break;
    case BOX:
    case BOX_ON_GOAL:
        // Need to look one square further then push box
        uint8_t r2 = r + y;
        uint8_t c2 = c + x;

        if(offScreen(r2,c2) ||
           board[r2][c2] == WALL ||
           board[r2][c2] == BOX ||
           board[r2][c2] == BOX_ON_GOAL)
        {
            sound.tone(NOTE_C1, NOTE_LENGTH);
            return;
        }

        if(board[r2][c2] == GOAL)
            sound.tone(NOTE_C3, NOTE_LENGTH, NOTE_E2, NOTE_LENGTH);
        else
            sound.tone(NOTE_C3, NOTE_LENGTH);


        // Push the box
        board[r2][c2] = board[r2][c2] == GOAL ? BOX_ON_GOAL : BOX;
        board[r][c] = board[r][c] == BOX_ON_GOAL ? PLAYER_ON_GOAL : PLAYER;
        break;
    default:
        // This should never happen!
        return;
    }

    // Set the board based on where the player WAS
    board[pr][pc] = board[pr][pc] == PLAYER_ON_GOAL ? GOAL : FLOOR;
    pr = r;
    pc = c;
    moves++;

    if(x == 1)
        undoBuffer[moves % MAX_UNDO] = 'l';
    else if(x == -1)
        undoBuffer[moves % MAX_UNDO] = 'r';
    else if(y == 1)
        undoBuffer[moves % MAX_UNDO] = 'd';
    else if(y == -1)
        undoBuffer[moves % MAX_UNDO] = 'u';

    if(undoCount < MAX_UNDO)
        undoCount++;
}

// This will reset the level after FRAMES_TO_RESET of the A button being held down
void reset()
{
    if (exploded) return;

    reset_count++;
    if(reset_count > FRAMES_TO_RESET)
    {
        gameState = STATE_LEVEL_INIT;
        exploded = true;
        reset_count = 0;
        return;
    }
    if(reset_count < FRAMES_TO_RESET * 0.9)
        arduboy.setRGBled(reset_count * 255 / FRAMES_TO_RESET, 0, 0);
    else
        arduboy.setRGBled(255, 255, 255);

    sound.tone(NOTE_C3 + reset_count, NOTE_LENGTH);
}

void undo(int8_t x, int8_t y)
{
#if DEBUG
    Serial.print("Undo ");
    Serial.print(x);
    Serial.print(", ");
    Serial.println(y);
#endif

    int8_t r = pr + y;
    int8_t c = pc + x;

    switch (board[r][c])
    {
    case FLOOR:
        board[r][c] = PLAYER;
        sound.tone(NOTE_C3, NOTE_LENGTH);
        break;
    case GOAL:
        sound.tone(NOTE_E3, NOTE_LENGTH);
        board[r][c] = PLAYER_ON_GOAL;
        break;
    case WALL:
    case BOX:
    case BOX_ON_GOAL:
    default:
        // This should never happen!
#if DEBUG
        Serial.print("Invalid square ");
        Serial.println(board[r][c]);
#endif
        return;
    }

    // Set the board based on where the player WAS
    board[pr][pc] = board[pr][pc] == PLAYER_ON_GOAL ? GOAL : FLOOR;

    // Are we pulling a box?
    int8_t br = pr - y;
    int8_t bc = pc - x;
    if(board[br][bc] == BOX || board[br][bc] == BOX_ON_GOAL)
    {
        if(board[pr][pc] == GOAL)
            sound.tone(NOTE_C3, NOTE_LENGTH, NOTE_E2, NOTE_LENGTH);
        else
            sound.tone(NOTE_C3, NOTE_LENGTH);

        // Pull the box
        board[pr][pc] = board[pr][pc] == GOAL ? BOX_ON_GOAL : BOX;
        board[br][bc] = board[br][bc] == BOX_ON_GOAL ? GOAL : FLOOR;
    }

    pr = r;
    pc = c;
    moves--;
    undoCount--;
}

void undo()
{
#if DEBUG
    Serial.println("Undo buffer;");
    for(int i = 0; i < MAX_UNDO; i++)
    {
        Serial.print(undoBuffer[i]);
        Serial.print(", ");
    }
    Serial.println();

    Serial.print("Undo move ");
    Serial.print(moves % MAX_UNDO);
    Serial.print(", ");
    Serial.println((char)undoBuffer[moves % MAX_UNDO]);
#endif

    if(undoCount == 0)
        return; // No more undos left

    switch(undoBuffer[moves % MAX_UNDO])
    {
        case 'l':
            undo(-1, 0);
            break;
        case 'r':
            undo(1, 0);
            break;
        case 'd':
            undo(0, -1);
            break;
        case 'u':
            undo(0, 1);
            break;
    }
}

void move()
{
    if(arduboy.justPressed(A_BUTTON))
        undo();
    else if(arduboy.pressed(A_BUTTON))
        reset();
    else if(arduboy.justReleased(A_BUTTON))
    {
        arduboy.setRGBled(0, 0, 0);
        exploded = false;
        reset_count = 0;
    }
    else if(arduboy.justPressed(UP_BUTTON))
        move(0, -1);
    else if(arduboy.justPressed(DOWN_BUTTON))
        move(0, 1);
    else if(arduboy.justPressed(RIGHT_BUTTON))
        move(1, 0);
    else if(arduboy.justPressed(LEFT_BUTTON))
        move(-1, 0);
    else if(arduboy.justPressed(B_BUTTON))
        gameState = STATE_GAME_INTRO;
}

bool isSolved()
{
    // Make sure all boxes are on goals
    for(int8_t r = 0; r < ROWS; r++)
    {
        for(int8_t c = 0; c < COLUMNS; c++)
        {
            if(board[r][c] == BOX)
                return false;
        }
    }
    return true;
}

void drawBoard()
{
    for(int8_t r = 0; r < ROWS; r++)
    {
        for(int8_t c = 0; c < COLUMNS; c++)
        {
            uint8_t x = c * WIDTH / COLUMNS;
            uint8_t y = r * HEIGHT / ROWS;
            switch (board[r][c])
            {
            case FLOOR:
                break;
            case PLAYER:
            case PLAYER_ON_GOAL:
                if(reset_count > 0)
                {
                    sprites.drawSelfMasked(x, y, Explode, reset_count / (FRAMES_TO_RESET / EXPLODE_FRAMES));
                }
                else
                {
                    sprites.drawSelfMasked(x, y, Player, frame / 20 % 4);
                }
                break;
            case WALL:
                sprites.drawSelfMasked(x, y, Wall, 0);
                break;
            case BOX:
                sprites.drawSelfMasked(x, y, Box, 0);
                break;
            case BOX_ON_GOAL:
                sprites.drawSelfMasked(x, y, BoxOnGoal, frame / 30 % 2);
                break;
            case GOAL:
                sprites.drawSelfMasked(x, y, Goal, frame / 15 % 4);
                break;
            }
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
    gameState = STATE_GAME_PLAY;
    moves = 0;
}

void gamePlay()
{
    move();
    if(isSolved())
    {
        sound.tone(NOTE_C4, NOTE_LENGTH, NOTE_E4, NOTE_LENGTH);
        gameState = STATE_LEVEL_SOLVED;
    }
    drawBoard();
}

void levelSolved()
{
    arduboy.setCursor(0, 10);
    arduboy.print("Level ");
    arduboy.print(level);
    arduboy.println(" solved in");
    arduboy.print(moves);
    arduboy.println(" moves!");
    arduboy.println();
    arduboy.println("A to go to the next");
    arduboy.println("level, B to return");
    arduboy.println("to the main menu.");
    if (arduboy.justPressed(A_BUTTON))
    {
        if(level < max_levels)
        {
            level++;
            gameState = STATE_LEVEL_INIT;
        }
        else
        {
            gameState = STATE_GAME_OVER;
        }
    }
    else if (arduboy.justPressed(B_BUTTON))
    {
        gameState = STATE_GAME_INTRO;
    }
}