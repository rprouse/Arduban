# Arduban

An attempt at a [Sokoban](http://sokobano.de/wiki/index.php?title=Main_Page) clone
for the [Arduboy](https://arduboy.com/). It uses levels created by
[David W. Skinner](http://www.abelmartin.com/rj/sokobanJS/Skinner/David%20W.%20Skinner%20-%20Sokoban.htm). This game makes use of the
[4x6 Font by Filmote](https://github.com/filmote/Font4x6) which is under the
BSD-3 license.

Intro Screen

![Intro Screen](./Assets/Images/Intro.png)

Level 8

![Level 8](./Assets/Images/Level8.png)

## Playing

The objective of the game is to move the man, pushing all of the boxes onto the
goal squares.

### Player

Our trusty player, ready and willing to push boxes around for a living!

![Player](./Assets/Images/Player.png)

### Box

These are the objective, push these onto the goals.

![Box](./Assets/Images/Box.png)

### Goal

This is where you want to push the boxes to.

![Goal](./Assets/Images/Goal.png)

### Box on Goal

This is the objective of the game, move boxes onto the goals in the least moves
possible.

![Box on Goal](./Assets/Images/BoxOnGoal.png)

### Wall

You can't move here...

![Wall](./Assets/Images/Wall.png)

### Up, Down, Left, Right Buttons

- Move the man.

### A Button

- Single press will undo one move up to a max of 128 moves
- Hold down to explode the man and reset the level

### B Button

- Return to the main screen

## ParseLevels

This .NET Core program takes levels in a simple TXT format and converts them
to C code to add into the `levels.h` file. The level files are in the `Assets\Levels`
directory.

This program looks at each level and skips levels that are bigger than 16x8 squares.
If a level is taller than it is wide, it rotates the level to fit better on the
Arduboy screen. It then centers the level if it is smaller than 16x8.

Lastly, it compresses the levels using a simple run length encoding (RLE) format
inspired by the the Sokoban XSB format, but modified to take fewer bytes of memory
on the Arduboy. As of this writing, I've managed to load 295 levels and use 89%
of memory. I will probably want to reduce that to around 255 levels to make room
for more bitmaps.

You must have .NET Core 2.1 installed. The utility is run with a command like the following;

```
dotnet run -- 'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Microban.txt' 'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Microban II.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Microban III.txt' 'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Microban IV.txt' 'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch II.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch III.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch IV.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch V.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch VI.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch VII.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch VIII.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch IX.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch X.txt'  'C:\src\Arduino\Arduboy\Arduban\Assets\Levels\Sasquatch XI.txt' > C:\src\Arduino\Arduboy\Arduban\Arduban\levels.h
```