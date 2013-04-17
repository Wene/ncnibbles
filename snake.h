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
    short getColorPair();
    bool checkSelfCollision();
    bool checkForeignCollision(point pos);
    point getHeadPosition();

private:
    std::vector<snakepart> parts;
    short colorPair;
    direction dir;
};

#endif // SNAKE_H
