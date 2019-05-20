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
#if DEBUG
  Serial.begin(115200);  // For debugging :)
  while(!Serial);
  Serial.println("OK");
#endif

  arduboy.begin();
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
  arduboy.display();

  frame++;
}