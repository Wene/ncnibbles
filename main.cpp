#include <ncurses.h>
#include "snake.h"
#include <unistd.h>

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
    int maxX = getmaxx(stdscr);
    int maxY = getmaxy(stdscr);
    snake s1(maxX - 8, maxY - 5, snake::left, 1);
    snake s2(8, 5,  snake::right, 2);
    int ch1 = 0;
    int ch2 = 0;
    while(ch1 != 27 && ch2 != 27)     //Loop until ESC is pressed
    {
        clear();
        s1.draw();
        s2.draw();
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
        if(s1.checkSelfCollision() || s2.checkSelfCollision())
        {
            usleep(500*1000);
        }
        if(s1.checkForeignCollision(s2.getHeadPosition()) ||
                s2.checkForeignCollision(s1.getHeadPosition()))
        {
            usleep(1000*1000);
        }

    }
    endwin();
    return 0;
}

