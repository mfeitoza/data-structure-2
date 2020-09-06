#define SIZE 10

struct User {
    char name[50];
    char rg[9];
    char cpf[11];
};

typedef User User;

typedef struct {
    int size;
    int total;
    User *data;
} List;

List *listInit();

void listInsert(List *list, User user);

void listPop(List *list);

int listLen(List *list);

void listPrint(List *list);
