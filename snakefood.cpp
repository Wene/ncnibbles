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
