#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "snakepart.h"
#include <ncurses.h>

class snake
{
public:
    snake();
    void draw();

private:
    std::vector<snakepart> parts;
};

#endif // SNAKE_H
