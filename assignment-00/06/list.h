#define SIZE 10

struct Data {
    char name[50];
    int id;
    char autor[50];
    char publishedAt[4];
};

typedef Data Data;

typedef struct {
    int size;
    int total;
    Data *data;
} List;

List *listInit();

void listInsert(List *list, Data data);

void listPop(List *list);

int listLen(List *list);

void listPrint(List *list);
