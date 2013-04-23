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
