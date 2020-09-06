#include <stdio.h>
#include <iostream>
#include <limits>

#define SIZE 5
using namespace std;

void printVector(int numbers[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ": " << numbers[i] << "\n";
    }
}

void printOdd(int numbers[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 != 0) {
            cout << i + 1 << ": " << numbers[i] << "\n";
        }
    }
}

void printEven(int numbers[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 == 0) {
            cout << i + 1 << ": " << numbers[i] << "\n";
        }
    }
}

int main(int argc, char *argv[]) {
    int numbers[SIZE];
    int i = 0;
    int n;
    int op = 0;

    while (i < SIZE) {
        cin.clear();
        cout << "Informe o númeo " << i + 1 << ": ";
        cin >> n;
        if (!cin.fail()) {
            numbers[i] = n;
            i++;
        } else {
            cout << "Número inválido. \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    cout << "\n";
    cout << "---\n";

    while (op != 4) {
        cout << "1) Exibir vetor informado\n";
        cout << "2) Exibir elementos ímpares\n";
        cout << "3) Exibir elementos pares\n";
        cout << "4) Encerrar o programa\n";
        cin >> op;

        switch (op) {
            case 1:
                printVector(numbers);
                break;
            case 2:
                printOdd(numbers);
                break;
            case 3:
                printEven(numbers);
                break;
        }
        cout << "\n";
    }


}