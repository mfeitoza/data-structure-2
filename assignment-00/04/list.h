#define SIZE 10

typedef struct {
    int size;
    int total;
    int *data;
} List;

List *listInit();

void listInsert(List *list, int n);

void listPop(List *list);

int listLen(List *list);

void listPrint(List *list);



