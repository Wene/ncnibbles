#ifndef SNAKEPART_H
#define SNAKEPART_H

struct point
{
    int x, y;
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
    bool isAt(int x, int y);
    point getPos();
    int getX();
    int getY();
    char getCharacter();

private:
    int xPos, yPos;
    char character;
};

#endif // SNAKEPART_H
