#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *listInit() {
    List *list;
    list = (List *) malloc (sizeof(List));
    list -> data = (int *) malloc (SIZE * sizeof(int));
    list -> size = 0;
    list -> total = SIZE;
    return list;
}

void listInsert(List *list, int n) {
    list -> data[list -> size] = n;
    list -> size++;

    if (list -> size == list -> total) {
        int new_size = list -> size + SIZE;
        list -> data = (int *) realloc (list -> data, new_size * sizeof(int));
        list -> total = new_size;
    }
}

void listPop(List *list) {
    if (list -> size > 0) {
        list -> data[list -> size - 1] = 0;
        list -> size--;
    }
}

int listLen(List *list) {
    return list -> size;
}

void listPrint(List *list) {
    for (int i = 0; i < list -> size; i++) {
        printf("%d: valor = %d\n", i + 1, list -> data[i]);
    }
}