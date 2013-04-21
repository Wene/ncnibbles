#include "snake.h"

snake::snake(int startX, int startY, direction startDir, short startColorPair)
{
    colorPair = startColorPair;
    dir = startDir;
    for(int i = 0; i < 5; i++)
    {
        point pos;
        pos.x = startX;
        pos.y = startY;
        switch(dir)
        {
        case left:
            pos.x += i;
            break;
        case right:
            pos.x -= i;
            break;
        case up:
            pos.y += i;
            break;
        case down:
            pos.y -= i;
            break;
        }
        snakepart part(pos);
        parts.push_back(part);
    }
    bGrow = false;
}

void snake::draw()
{
    color_set(colorPair,0);
    for(unsigned int i = 0; i < parts.size(); i++)
    {
        snakepart part = parts.at(i);
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
    if(!bGrow)
    {
        parts.pop_back();
    }
    else
    {
        bGrow = false;
    }
}

void snake::setColorPair(short col)
{
    colorPair = col;
}

void snake::grow()
{
    bGrow = true;
}

short snake::getColorPair()
{
    return colorPair;
}

bool snake::checkSelfCollision()
{
    snakepart head = parts.at(0);
    for(unsigned int i = 4; i < parts.size(); i++)
    {
        snakepart part = parts.at(i);
        if(head.isAt(part.getPos()))
        {
            return true;
        }
    }
    return false;
}

bool snake::checkForeignCollision(point pos)
{
    for(unsigned int i = 0; i < parts.size(); i++)
    {
        snakepart part = parts.at(i);
        if(part.isAt(pos))
        {
            return true;
        }
    }
    return false;
}

point snake::getHeadPosition()
{
    snakepart head = parts.at(0);
    return head.getPos();
}

unsigned int snake::getPoints()
{
    return parts.size() - 4;
}
