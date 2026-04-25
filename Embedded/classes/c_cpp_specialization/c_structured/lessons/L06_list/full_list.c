#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {
    int data;
    struct list *next;
} list;

int isEmpty(const list *l) {
    return (l == NULL);
}

list* createList(int d) {
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* addToFront(int d, list* h) {
    list* head = createList(d);
    head -> next = h;
    return head;
}

list* arrayToList(int d[], int size) {
    list* head = createList(d[0]);
    for(int i = 1; i < size; i++) {
        head = addToFront(d[i], head);
    }
    return head;
}

void printList(list *h, char *title) {
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d: ", h -> data);
        h = h -> next;
    }
}

int main() {
    list listOfInt;
    list* head = NULL;
    int data[6] = {2, 3, 5, 7, 8, 9};
    head = arrayToList(data, 6);
    printList(head, "Single element list");
    printf("\n\n");
    return 0;
}