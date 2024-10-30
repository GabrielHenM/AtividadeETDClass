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
        Node* toDel = last;
        Node* aux = first;
        while (aux->next != last) {
            aux = aux->next;
        }
        last = aux;
        last->next = NULL;
        delete toDel;
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

    void removeSecond() {
        if (c < 2) return;

        if (c == 2) {
            popBack();
            return;
        }

        Node* toDel = first->next;
        first->next = toDel->next;
        delete toDel;
        c--;
    }
};

int main() {
    List l;

    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(5);

    l.removeSecond();

    l.print();

    return 0;
}
