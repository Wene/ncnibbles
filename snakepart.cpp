#include "snakepart.h"

#include <ncurses.h>

snakepart::snakepart()
{
    xPos = 1;
    yPos = 1;
    character = '@';
}

snakepart::snakepart(int x, int y)
{
    xPos = x;
    yPos = y;
    character = '@';
}

snakepart::snakepart(point pos)
{
    xPos = pos.x;
    yPos = pos.y;
    character = '@';
}

void snakepart::setCharacter(char ch)
{
    character = ch;
}

void snakepart::setPos(int x, int y)
{
    xPos = x;
    yPos = y;
}

void snakepart::setPos(point pos)
{
    xPos = pos.x;
    yPos = pos.y;
}

bool snakepart::isAt(int x, int y)
{
    if(x == xPos && y == yPos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

point snakepart::getPos()
{
    point Pos;
    Pos.x = xPos;
    Pos.y = yPos;
    return Pos;
}

int snakepart::getX()
{
    return xPos;
}

int snakepart::getY()
{
    return yPos;
}

char snakepart::getCharacter()
{
    return character;
}
