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

bool snakepart::isAt(point pos)
{
    if(xPos == pos.x && yPos == pos.y)
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
