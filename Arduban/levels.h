#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"

#define MAX_LEVELS 2

const char levels[MAX_LEVELS][ROWS][COLUMNS] PROGMEM = {
    {   // Microban level 1
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ','#',' ',' ','*',' ',' ','#',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ','#',' ',' ','@',' ','.','#',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ','#','#','$',' ','#','#','#',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    },
    {   // Microban level 6
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ','#','#','#','#','#','#',' ','#','#','#','#','#',' ',' '},
        {' ',' ','#',' ',' ',' ',' ','#','#','#',' ',' ',' ','#',' ',' '},
        {' ',' ','#',' ','$','$',' ',' ',' ',' ',' ','#','@','#',' ',' '},
        {' ',' ','#',' ','$',' ','#','.','.','.',' ',' ',' ','#',' ',' '},
        {' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' '},
        {' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    }
};

#endif