#include <iostream>
#include <ncurses.h>
#include "snake.h"

int main()
{
    initscr();
    noecho();
    curs_set(0);
    move(3,10);
    printw("Häüö");
    snake s1;
    s1.draw();
    refresh();
    getch();
    endwin();
    return 0;
}

