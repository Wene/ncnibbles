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

#ifndef SNAKEPART_H
#define SNAKEPART_H

struct point
{
    int x, y;
    bool operator==(point p1)
    {
        if(p1.x == x && p1.y == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class snakepart
{
public:
    snakepart();
    snakepart(int x, int y);
    snakepart(point pos);
    void setPos(int x, int y);
    void setPos(point pos);
    void setCharacter(char ch);
    bool isAt(point pos);
    point getPos();
    int getX();
    int getY();
    char getCharacter();

private:
    int xPos, yPos;
    char character;
};

#endif // SNAKEPART_H
