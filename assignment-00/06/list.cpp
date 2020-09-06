#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *listInit() {
    List *list;
    list = (List *) malloc (sizeof(List));
    list -> data = (Data *) malloc (sizeof(Data) * SIZE);
    list -> size = 0;
    list -> total = SIZE;
    return list;
}

void listInsert(List *list, Data data) {
    list -> data[list -> size] = data;
    list -> size++;

    if (list -> size == list -> total) {
        int new_size = list -> size + SIZE;
        list -> data = (Data *) realloc (list -> data, new_size * sizeof(Data));
        list -> total = new_size;
    }
}

void listPop(List *list) {
    if (list -> size > 0) {
        Data empty;
        list -> data[list -> size - 1] = empty;
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