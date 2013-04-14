#include "snake.h"

snake::snake()
{
    for(int i = 0; i < 30; i++)
    {
        snakepart part(10+i,5);
        parts.push_back(part);
    }
}

void snake::draw()
{
    for(unsigned int i = 0; i < parts.size(); i++)
    {
        snakepart part = parts.at(i);
        move(part.getY(), part.getX());
        printw("%c",part.getCharacter());
    }
}
