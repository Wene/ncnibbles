/*
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2004 Sam Hocevar
  14 rue de Plaisance, 75014 Paris, France
 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.

*/

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "snakepart.h"
#include <ncurses.h>


class snake
{
public:
    enum direction
    {
        up,
        down,
        left,
        right
    };
    snake(int startX, int startY, direction startDir, short startColorPair);
    void draw();
    void turn(direction nextDir);
    void moveOneStep();
    void setColorPair(short col);
    void grow();
    short getColorPair();
    bool checkSelfCollision();
    bool checkForeignCollision(point pos);
    point getHeadPosition();
    unsigned int getPoints();

private:
    std::vector<snakepart> parts;
    short colorPair;
    direction dir;
    bool bGrow;
};

#endif // SNAKE_H
