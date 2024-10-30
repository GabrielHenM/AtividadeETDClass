#include <stdio.h>

struct Node {
    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct List {
    Node* first;
    Node* last;
    int c;

    List() {
        first = NULL;
        last = NULL;
        c = 0;
    }

    bool empty() {
        return first == NULL;
    }

    void pushFront(int value) {
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->next = first;
        first = n;
    }

    void pushBack(int value) {
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void popFront() {
        if (empty()) return;
        if (c == 1) {
            delete(first);
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete toDel;
        c--;
    }

    void popBack() {
        if (empty()) return;
        if (c == 1) {
            delete(first);
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* aux = first;
        while (aux->next != last) {
            aux = aux->next;
        }
        delete last;
        last = aux;
        last->next = NULL;
        c--;
    }

    void print() {
        Node* aux = first;
        while (aux != NULL) {
            printf("%d", aux->value);
            aux = aux->next;
            if (aux != NULL) {
                printf(" -> ");
            }
        }
        printf("\n");
    }

    void removeLastN(int N) {
        if (empty() || N <= 0) return;

        if (N >= c) {
            while (!empty()) {
                popFront();
            }
            return;
        }

        int newSize = c - N;
        Node* aux = first;

        for (int i = 1; i < newSize; i++) {
            aux = aux->next;
        }

        Node* toDelete = aux->next;
        aux->next = NULL;
        last = aux;

        while (toDelete != NULL) {
            Node* next = toDelete->next;
            delete toDelete;
            toDelete = next;
        }

        c = newSize;
    }
};

int main() {

    List l;

    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(5);

    l.removeLastN(2);

    l.print();
    return 0;
}
