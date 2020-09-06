#include <iostream>

#include "LinkedList.h"
#include "App.cpp"

using namespace std;

void printArray(int data) {
    cout << data << endl;
}

bool test(int data) {
    return data == -10;
}

int main (int argc, char *argv[]) {
    App app;
    app.init();
}