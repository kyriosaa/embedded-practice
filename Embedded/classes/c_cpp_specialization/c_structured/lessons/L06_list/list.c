// The ADT List

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

void printList(list *h, char *title) {
    printf("%s\n", title);
    while(h != NULL) {
        printf("%d :", h -> data);
        h = h -> next;
    }
}

int main() {
    list listOfInt;
    list* head = NULL;
    head = malloc(sizeof(list));

    printf("sizeof(list) = %lu\n", sizeof(list));
    head -> data = 5;
    head -> next = NULL;
    printList(head, "Single element list");
    printf("\n\n");

    return 0;
}