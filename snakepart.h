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
