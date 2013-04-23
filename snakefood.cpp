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

#include "snakefood.h"

snakefood::snakefood(short color)
{
    srand(time(NULL));
    visible = true;
    symbol = '*';
    colorPair = color;
    newPosition();
}

bool snakefood::isVisible()
{
    return visible;
}

void snakefood::setVisible(bool vis)
{
    visible = vis;
}

point snakefood::getPosition()
{
    point pos;
    pos.x = xPos;
    pos.y = yPos;
    return pos;
}

point snakefood::newPosition()
{
    xPos = rand() % getmaxx(stdscr);
    yPos = rand() % getmaxy(stdscr);
    return getPosition();
}

void snakefood::draw()
{
    if(visible)
    {
        color_set(colorPair, 0);
        move(yPos, xPos);
        printw("%c", symbol);
    }
}
