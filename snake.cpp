#include "snake.h"

snake::snake()
{
    color = COLOR_YELLOW;
    for(int i = 0; i < 20; i++)
    {
        snakepart part(30+i,5);
        parts.push_back(part);
    }
    dir = left;
}

void snake::draw()
{
    init_pair(1,color,COLOR_BLACK);
    for(unsigned int i = 0; i < parts.size(); i++)
    {
        snakepart part = parts.at(i);
        color_set(1,0);
        move(part.getY(), part.getX());
        printw("%c",part.getCharacter());
    }
}

void snake::turn(direction nextDir)
{
    //check if the direction is changed and possible
    if((dir == up || dir == down) && (nextDir == right || nextDir == left))
    {
        dir = nextDir;
    }
    else if((dir == left || dir == right) && (nextDir == up || nextDir == down))
    {
        dir = nextDir;
    }
}

void snake::moveOneStep()
{
    int maxX = getmaxx(stdscr) - 1;
    int maxY = getmaxy(stdscr) - 1;
    snakepart lastPart = parts.at(0);
    point pos = lastPart.getPos();
    switch(dir)
    {
    case right:
        pos.x++;
        break;
    case left:
        pos.x--;
        break;
    case up:
        pos.y--;
        break;
    case down:
        pos.y++;
        break;
    }

    //endless screen
    if(pos.x > maxX)
        pos.x = 0;
    else if(pos.x < 0)
        pos.x = maxX;
    if(pos.y > maxY)
        pos.y = 0;
    else if(pos.y < 0)
        pos.y = maxY;

    snakepart newPart;
    newPart.setPos(pos);
    parts.insert(parts.begin(),newPart);
    parts.pop_back();
}

void snake::setColor(short col)
{
    color = col;
}

short snake::getColor()
{
    return color;
}
