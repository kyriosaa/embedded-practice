#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure for a node in the linked list
// contains an int data and a pointer to the next node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// create new node
Node* createNode(int data) {
    // allocates memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // initializes newNode with given data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// append node to linked list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);

    // if the head doesnt exist, make that the newNode
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;

    // make the next node temp
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// generate 100 random numbers & append to linked list
void generateRandList(Node** head) {
    for(int i = 0; i < 100; i++) {
        appendNode(head, rand() % 1000); // keep it under 1000
    }
}

// bubble sort
void bubbleSort(Node* head) {
    if(head == NULL) {
        return;
    }

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while(ptr1->next != lptr) {
            if(ptr1->data > ptr1->next->data) {
                // swap
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

// print linked list in rows of 5
void printList(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        printf("%4d ", temp->data);
        count++;

        if(count % 5 == 0) {
            printf("\n");
        }
        temp = temp->next;
    }

    if(count % 5 != 0) {
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed for random num
    Node* head = NULL;

    generateRandList(&head);

    printf("Original List:\n");
    printList(head);

    bubbleSort(head);

    printf("\nSorted List:\n");
    printList(head);

    return 0;
}