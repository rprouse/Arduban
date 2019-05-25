#include "intro.h"
#include "load.h"
#include "game.h"
#include "solved.h"
#include "over.h"
#include "memory.h"
#include "settings.h"

typedef void (*FunctionPointer)();

const FunctionPointer PROGMEM gameStates[] = {
  gameIntro,
  loadLevel,
  gamePlay,
  levelSolved,
  gameOver,
  settings
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