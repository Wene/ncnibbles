#include <ncurses.h>
#include "snake.h"
#include <unistd.h>
#include <cstdlib>  //for rand()
#include <time.h>

int main()
{
    srand(time(NULL));
    initscr();
    noecho();
    keypad(stdscr, true);
    cbreak();
    nodelay(stdscr, true);
    curs_set(0);
    start_color();
    snake s1;
    int ch = 0;
    while(ch != 27)     //Loop until ESC is pressed
    {
        clear();
        s1.draw();
        refresh();
        usleep(60*1000);
        ch = getch();
        switch(ch)
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
        }
        s1.moveOneStep();
    }
    getch();
    endwin();
    return 0;
}

