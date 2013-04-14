#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "snakepart.h"
#include <ncurses.h>


class snake
{
public:
    snake();
    enum direction
    {
        up,
        down,
        left,
        right,
    };
    void draw();
    void turn(direction nextDir);
    void moveOneStep();
    void setColor(int col);
    short getColor();


private:
    std::vector<snakepart> parts;
    short color;
    direction dir;
};

#endif // SNAKE_H
