#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "snakepart.h"
#include <ncurses.h>

enum direction
{
    up,
    down,
    left,
    right
};

class snake
{
public:
    snake();
    void draw();
    void turn(direction dir);

private:
    std::vector<snakepart> parts;
};

#endif // SNAKE_H
