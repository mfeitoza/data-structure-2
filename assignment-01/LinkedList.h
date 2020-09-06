#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList {
    T null;
    protected:
        class Node {
            public:
                T data;
                Node *next;
                Node(T value) {
                    data = value;
                    next = NULL;
                }
        };
        Node *head;
        Node *tail;
        int n;
    
    public:
        LinkedList() {
            null = (T)NULL;
            n = 0;
            head = tail = NULL;
        }

        ~LinkedList() {
            Node *node = head;
            while (node != NULL) {
                Node *t = node;
                node = node -> next;
                delete t;
            }
        }

        int size() {
            return n;
        }

        // add to the end of list
        int add(T data) {
            Node *node = new Node(data);
            if (n == 0) {
                head = node;
            } else {
                tail -> next = node;
            }
            tail = node;
            n++;
            return n;
        }

        // add to init of list
        int push(T data) {
            Node *node = new Node(data);
            node -> next = head;
            head = node;
            if (n == 0) {
                tail = node;
            }
            n++;
            return n;
        }
        
        // remove last item
        int pop() {
            int i = 0;
            Node *node = head;
            while (node != NULL && i < n - 2) {
                node = node -> next;
                i++;
            }
            tail = node;
            tail -> next = NULL;
            delete node -> next;
            n--;
            if (n == 0) {
                head = NULL;
            }
            return n;
        }

        // remove first item
        int shift() {
            if (n == 0) return 0;
            Node *node = head;
            head = head -> next;
            delete node;
            n--;
            if (n == 0) tail = NULL;
            return n;
        }

        // loop through list and pass data to callback
        void forEach(void (*fn)(T data, int index)) {
            int index = 0;
            Node *node = head;
            while (node != NULL) {
                T data = node -> data;
                fn(data, index);
                node = node -> next;
                index++;
            }
        }

        bool isEmpty() {
            return n == 0;
        }

        int indexOf(T value) {
            int i = 0;
            bool found = false;
            Node *node = head;
            while (node != NULL && !found) {
                if (node -> data == value) {
                    found = true;
                }
                node = node -> next;
                i++;
            }
            if (found) return i;
            return -1;
        }

        T getByIndex(int index) {
            int i = 0;
            Node *node = head;
            while (node != NULL && i < index - 1) {
                node = node -> next;
                i++;
            }
            return node -> data;
        }

        T getHead() {
            return head -> data;
        }

        T getTail() {
            return tail -> data;
        }
};

#endif