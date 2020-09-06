#include <stdio.h>
#include <curses.h>
#include <iostream>


#define ESC 27

using namespace std;

int main(int argc, char *argv[]) {
  bool exit = false;
  int ch;

  initscr();
  noecho();
  timeout(500);

  do {
    ch = getch();
    if (ch != -1) {
      printw("Caractere: %c | Dec.  ASCII: %d\n", ch, ch);
      refresh();
    }

    if (ch == ESC) {
      exit = true;
    }
  } while (!exit);
  endwin();
  return 0;
}