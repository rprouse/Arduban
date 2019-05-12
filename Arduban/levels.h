#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"

const char levels[1][ROWS][COLUMNS] PROGMEM = {
    {
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