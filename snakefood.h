#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include "snakepart.h"
#include <cstdlib>  //for rand()
#include <time.h>
#include <ncurses.h>

class snakefood
{
public:
    snakefood(short color);
    point getPosition();
    point newPosition();
    bool isVisible();
    void setVisible(bool vis);
    void draw();

private:
    int xPos, yPos;
    bool visible;
    char symbol;
    short colorPair;
};

#endif // SNAKEFOOD_H
