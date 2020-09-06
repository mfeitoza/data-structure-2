#include <stdio.h>
#include <iostream>
#include <string.h>
#include "minctest.h"

#include "list.h"

using namespace std;

void testInit () {
    List *l;
    l = listInit();

    lok(l -> size == 0);
    lok(l -> total == SIZE);
}

User createUser () {
    User u;
    strcpy(u.name, "User");
    strcpy(u.rg, "111111111");
    strcpy(u.name, "11111111111");
    return u;
}

void testInsert () {
    List *l;
    l = listInit();

    User a = createUser();
    User b = createUser();

    listInsert(l, a);
    listInsert(l, b);

    lok(l -> size = 2);
}

void testPop () {
    List *l;
    l = listInit();

    User a = createUser();
    User b = createUser();

    listInsert(l, a);
    listInsert(l, b);

    listPop(l);
    lok(l -> size = 1);
}

void testLen () {
    List *l;
    l = listInit();

    User a = createUser();
    User b = createUser();

    listInsert(l, a);
    listInsert(l, b);

    lok(l -> size = 2);

    listPop(l);
    lok(l -> size = 1);
}

int main (int argc, char *argv[]) {
    cout << "-------------------" << endl;
    cout << "List testes" << endl;
    cout << "-------------------" << endl;
    lrun("inicia", testInit);
    lrun("insere", testInsert);
    lrun("remove", testPop);
    lrun("tamanho", testLen);
    lresults();
}