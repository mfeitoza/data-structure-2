#include <stdio.h>
#include <iostream>
#include "minctest.h"

#include "list.h"

using namespace std;

void testInit () {
    List *l;
    l = listInit();

    lok(l -> size == 0);
    lok(l -> total == SIZE);
}

void testInsert () {
    List *l;
    l = listInit();

    int a = 2;
    int b = 7;
    listInsert(l, a);
    listInsert(l, b);

    lok(l -> size = 2);
    lok(l -> data[0] == a);
    lok(l -> data[1] == b);
}

void testPop () {
    List *l;
    l = listInit();

    int a = 2;
    int b = 7;
    listInsert(l, a);
    listInsert(l, b);

    listPop(l);
    lok(l -> size = 1);
    lok(l -> data[1] != b);
}

void testLen () {
    List *l;
    l = listInit();

    int a = 2;
    int b = 7;
    listInsert(l, a);
    listInsert(l, b);
    lok(l -> size = 2);

    listPop(l);
    lok(l -> size = 1);
}

void testResize () {
    List *l;
    l = listInit();

    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    lok(l -> size == 9);
    lok(l -> total == SIZE);
    listInsert(l, 1);
    listInsert(l, 1);
    listInsert(l, 1);
    lok(l -> size == 12);
    lok(l -> total == SIZE * 2);
}

void testPrint () {
    List *l;
    l = listInit();

    listInsert(l, 1);
    listInsert(l, 3);
    listInsert(l, 85);
    listInsert(l, 523);
    listInsert(l, 48);
    listInsert(l, 31);
    listInsert(l, 88);
    listInsert(l, 10);
    listInsert(l, 12);
    listPrint(l);
}

int main (int argc, char *argv[]) {
    cout << "-------------------" << endl;
    cout << "List testes" << endl;
    cout << "-------------------" << endl;
    lrun("inicia", testInit);
    lrun("insere", testInsert);
    lrun("remove", testPop);
    lrun("tamanho", testLen);
    lrun("dinamico", testResize);
    testPrint();
    lresults();
}