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

#include <ncurses.h>
#include <unistd.h>
#include "snake.h"
#include "snakefood.h"

int main()
{
    initscr();
    noecho();
    keypad(stdscr, true);
    cbreak();
    nodelay(stdscr, true);
    curs_set(0);
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_BLUE, COLOR_BLACK);
    init_pair(3,COLOR_RED, COLOR_BLACK);
    int maxX = getmaxx(stdscr);
    int maxY = getmaxy(stdscr);
    snake s1(maxX - 8, maxY - 5, snake::left, 1);
    snake s2(8, 5,  snake::right, 2);
    snakefood f1(3);
    int ch1 = 0;
    int ch2 = 0;
    while(ch1 != 27 && ch2 != 27)     //Loop until ESC is pressed
    {
        clear();

        //If food isn't visible or outer screen, set new position
        point foodPos = f1.getPosition();
        if(foodPos.x > getmaxx(stdscr) || foodPos.y > getmaxy(stdscr) || !f1.isVisible())
        {
            bool collision = true;
            while(collision)
            {
                foodPos = f1.newPosition();
                if(s1.checkForeignCollision(foodPos) ||
                        s1.checkForeignCollision(foodPos))
                {
                    foodPos = f1.newPosition();
                }
                else
                {
                    collision = false;
                }
            }
            f1.setVisible(true);
        }

        s1.draw();
        s2.draw();
        f1.draw();
        refresh();
        usleep(60*1000);
        //get two keys per step for both players
        ch1 = getch();
        ch2 = getch();
        switch(ch1)
        {
        case KEY_UP:
            s1.turn(snake::up);
            break;
        case KEY_DOWN:
            s1.turn(snake::down);
            break;
        case KEY_LEFT:
            s1.turn(snake::left);
            break;
        case KEY_RIGHT:
            s1.turn(snake::right);
            break;
        case 119:                    //'w'
            s2.turn(snake::up);
            break;
        case 115:                    //'s'
            s2.turn(snake::down);
            break;
        case 97:                     //'a'
            s2.turn(snake::left);
            break;
        case 100:                    //'d'
            s2.turn(snake::right);
            break;
        }
        switch(ch2)
        {
        case KEY_UP:
            s1.turn(snake::up);
            break;
        case KEY_DOWN:
            s1.turn(snake::down);
            break;
        case KEY_LEFT:
            s1.turn(snake::left);
            break;
        case KEY_RIGHT:
            s1.turn(snake::right);
            break;
        case 87:                    //'w'
            s2.turn(snake::up);
            break;
        case 83:                    //'s'
            s2.turn(snake::down);
            break;
        case 65:                    //'a'
            s2.turn(snake::left);
            break;
        case 68:                    //'d'
            s2.turn(snake::right);
            break;
        }

        s1.moveOneStep();
        s2.moveOneStep();

        //eat and grow
        if(s1.getHeadPosition() == f1.getPosition())
        {
            s1.grow();
            f1.setVisible(false);
        }
        if(s2.getHeadPosition() == f1.getPosition())
        {
            s2.grow();
            f1.setVisible(false);
        }

        //Collision detection
        if(s1.checkSelfCollision() || s2.checkSelfCollision())
        {
            break;
        }
        if(s1.checkForeignCollision(s2.getHeadPosition()) ||
                s2.checkForeignCollision(s1.getHeadPosition()))
        {
            break;
        }
    }
    int midX = getmaxx(stdscr)/2;
    int midY = getmaxy(stdscr)/2;
    nodelay(stdscr, false);
    color_set(3,0);
    move(midY, midX-6);
    printw(" game over ");
    move(midY+1, midX);
    printw(":");
    color_set(1,0);
    move(midY+1, midX-4);
    printw("%i",s1.getPoints());
    color_set(2,0);
    move(midY+1, midX+1);
    printw("%i",s2.getPoints());
    getch();
    endwin();
    return 0;
}

