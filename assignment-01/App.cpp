#include <stdio.h>
#include <iostream>

#include "LinkedList.h"

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define BLUE    "\033[34m" 
#define GREEN   "\033[32m" 


class App {
    protected:
        int op = 0;
        LinkedList<int> list;

        void printMenu() {
            std::cout << std::endl;
            std::cout << BLUE << "MENU" << RESET << std::endl;
            std::cout << BLUE << "====" << RESET << std::endl;
            std::cout << "1. Inserir" << std::endl;
            std::cout << "2. Remover o primeiro" << std::endl;
            std::cout << "3. Remover o útlimo" << std::endl;
            std::cout << "4. Mostrar o primeiro" << std::endl;
            std::cout << "5. Mostrar o último" << std::endl;
            std::cout << "6. Mostrar por indíce" << std::endl;
            std::cout << "7. Indice do valor" << std::endl;
            std::cout << "8. Verificar se esta vazia" << std::endl;
            std::cout << "9. Pesquisar valor" << std::endl;
            std::cout << "10. Mostrar lista" << std::endl;
            std::cout << "11. Sair" << std::endl;
        }

        int readValue() {
            int value;
            std::cout << "Valor: ";
            std::cin >> value;
            return value;
        }

        void insert () {
            std::cout << "Inserir:" << std::endl;
            list.add(readValue());
            std::cout << GREEN << "Inserido com sucesso!" << RESET << std::endl;
        }

        void removeFirst() {
            list.pop();
            std::cout << GREEN << "Removido com sucesso!" << RESET << std::endl;
        }

        void removeLast() {
            list.shift();
            std::cout << GREEN << "Removido com sucesso!" << RESET << std::endl;
        }

        void printFirst() {
            std::cout << GREEN << "Primeiro item: " << list.getHead() << RESET <<  std::endl;
        }

        void printLast() {
            std::cout << GREEN << "Último item: " << list.getTail() << RESET <<  std::endl;
        }

        void printByIndex() {
            int result;
            std::cout << "Retorn valor pelo indice" << std::endl;
            result = list.getByIndex(readValue());
            std::cout << GREEN << "Resultado: " << result << RESET << std::endl;
        }

        void indexOfValue() {
            int result;
            std::cout << "Pesquisar indice do valor" << std::endl;
            result = list.indexOf(readValue());
            std::cout << GREEN << "Resultado: " << result << RESET << std::endl;
        }

        void isEmptyList() {
            if (list.isEmpty()) {
                std::cout << GREEN << "A lista está vazia!" << RESET << std::endl;
            } else {
                std::cout << GREEN << "A lista não está vazia!" << RESET << std::endl;
            }
        }

        void searchValue() {
            int result;
            std::cout << "Pesquisar valor" << std::endl;
            result = list.indexOf(readValue());
            if (result != -1) {
                std::cout << GREEN << "Valor encontrado: " << list.getByIndex(result) << RESET << std::endl;
            } else {
                std::cout << GREEN << "Valor não encontrado!" << RESET << std::endl;
            }
        }

        void printList() {
            list.forEach([](int data, int index) {
                std::cout << GREEN << "Indice " << index + 1 << ": " << data << RESET << std::endl;
            });
        }

    public:
        void init() {
            list.add(11);
            list.add(12);
            list.add(13);
            list.add(14);
            list.add(15);
            std::cout << "-----------------" << std::endl;
            std::cout << "LISTA DE INTEIROS" << std::endl;
            std::cout << "-----------------" << std::endl;
            while (op != 11) {
                printMenu();
                std::cin >> op;
                switch (op)
                {
                case 1:
                    insert();
                    break;
                case 2:
                    removeFirst();
                    break;
                case 3:
                    removeLast();
                    break;
                case 4:
                    printFirst();
                    break;
                case 5:
                    printLast();
                    break;
                case 6:
                    printByIndex();
                    break;
                case 7:
                    indexOfValue();
                    break;
                case 8:
                    isEmptyList();
                    break;
                case 9:
                    searchValue();
                    break;
                case 10:
                    printList();
                    break;
                case 11:
                    break;
                default:
                    std::cout << RED << "OPÇÃO INVÁLIDA!" << RESET << std::endl;
                    break;
                }
            }
        }
};
