#include <stdio.h>
#include <stdlib.h>

typedef char DATA;
struct node {
    DATA d;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
typedef NODE *BTREE;

void inOrder(BTREE root) {
    if(root != NULL) {
        inOrder(root -> left);
        printf("%c ", root -> d);
        inOrder(root -> right);

    }
}

BTREE newNode(void) {
    return (malloc(sizeof(NODE)));
}

BTREE initNode(DATA d1, BTREE p1, BTREE p2) {
    BTREE t;
    t = newNode();
    t -> d = d1;
    t -> left = p1;
    t -> right = p2;
    return t;
}

BTREE createTree(DATA a[], int i, int size) {
    if(i >= size) {
        return NULL;
    } else {
        return (
            initNode(
                a[i], 
                createTree(a, 2 * i + 1, size),
                createTree(a, 2 * i + 2, size)
            )
        );
    }
}

int main() {
    char d[] = {'a', 'b', 'c', 'd', 'e'};
    BTREE b = createTree(d, 0, 5);
    inOrder(b);
    printf("\n\n");
    return 0;
}