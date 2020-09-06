#include <stdio.h>
#include <curses.h>
#include <iostream>

#include "list.h"

#define ESC_KEY 27
#define ENTER_KEY 10

using namespace std;

void printList(List *l) {
  printf("\n");
  printf("Tabela\n");
  for (int i = 0; i < l -> size; i++) {
    if (l -> data[i] == ENTER_KEY) {
      printf("%d: ENTER > 10 \n", i + 1);
    } else {
      printf("%d: %d > %c \n", i + 1, l -> data[i], l -> data[i]);
    }
  }
}

int main(int argc, char *argv[]) {
  bool exit = false;
  int ch;
  List *l;
  l = listInit();

  initscr();
  noecho();
  timeout(500);

  do {
    ch = getch();
    if (ch != -1 && ch != ESC_KEY) {
      listInsert(l, ch);
      printw("%c", ch);
      refresh();
    }

    if (ch == ESC_KEY) {
      
      exit = true;
    }
  } while (!exit);
  endwin();
  printList(l);
  return 0;
}