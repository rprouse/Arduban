// Template for starting Arduboy game projects
//
// Thanks to JO3RI for some of the ideas
//
// License: MIT
#include "intro.h"
#include "game.h"
#include "over.h"
#include "memory.h"

typedef void (*FunctionPointer)();

const FunctionPointer PROGMEM gameStates[] = {
  gameIntro,
  loadLevel,
  gamePlay,
  levelSolved,
  gameOver
};

void setup()
{
  Serial.begin(9600);  // For debugging and screenshotting

  arduboy.begin();
  arduboy.initRandomSeed();
  arduboy.setFrameRate(60);
  initEEPROM();
  level = getLevel();
}

void loop()
{
  if(!arduboy.nextFrame())
    return;

  arduboy.pollButtons();
  arduboy.clear();
  ((FunctionPointer)pgm_read_word(&gameStates[gameState]))();

#if !DEBUG
  // For screenshots
  Serial.write(arduboy.getBuffer(), 128 * 64 / 8);
#endif
  arduboy.display();

  frame++;
}