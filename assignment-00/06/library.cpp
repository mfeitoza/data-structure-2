#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include "list.h"

using namespace std;

void menu() {
    cout << "\nMENU\n";
    cout << "----\n";
    cout << "1- Cadastrar livro\n";
    cout << "2- Consultar todos os livros\n";
    cout << "3- Sair\n";
}

void libraryAddBook(List *list) {
    Data book;
    char name[50];
    int id;
    char autor[50];
    char publishedAt[4];

    cout << "Informe o nome: ";
    cin.ignore();
    cin.getline(name, sizeof(name));

    cout << "Informe o COD.: ";
    cin >> id;

    cout << "Informe o autor: ";
    cin.ignore();
    cin.getline(autor, sizeof(autor));

    cout << "Informe o ano de pub.: ";
    cin >> publishedAt;

    
    strcpy(book.name, name);
    book.id = id;
    strcpy(book.autor, autor);
    strcpy(book.publishedAt, publishedAt);

    listInsert(list, book);
}

void libraryPrintAllBooks(List *list) {
    const int w = 14;
    const char separator = ' ';
    cout << left << setw(w) << setfill(separator) << "Livro";
    cout << "| ";
    cout << left << setw(w) << setfill(separator) << "Codigo";
    cout << "| ";
    cout << left << setw(w) << setfill(separator) << "Autor";
    cout << "| ";
    cout << left << setw(w) << setfill(separator) << "Ano";
    cout << endl;
    for (int i = 0; i < list -> size; i++) {
        cout << left << setw(w) << setfill(separator) << list -> data[i].name;
        cout << "| ";
        cout << left << setw(w) << setfill(separator) << list -> data[i].id;
        cout << "| ";
        cout << left << setw(w) << setfill(separator) << list -> data[i].autor;
        cout << "| ";
        cout << left << setw(w) << setfill(separator) << list -> data[i].publishedAt;
        cout << endl;
    }
}

void start() {
    List *list = listInit();
    int op = 0;

    cout << "BIBLICOTECA\n";
    cout << "-----------\n";
    while (op != 3) {
        menu();
        cin >> op;
        switch(op) {
            case 1:
                libraryAddBook(list);
                break;
            case 2:
                libraryPrintAllBooks(list);
                break;
        }
    }
}