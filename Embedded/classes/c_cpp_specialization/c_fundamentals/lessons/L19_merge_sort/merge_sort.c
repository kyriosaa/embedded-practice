#include <stdio.h>

#define SIZE 5

void printArray();
void merge();

int main() {
    int a[SIZE] = {67, 82, 83, 88, 99};
    int b[SIZE] = {58, 69, 72, 81, 88};
    int c[SIZE * 2];  // since it has to hold both array a and b
    
    printArray(a, SIZE, "My grades\n");
    printf("\n\n");
    printArray(b, SIZE, "More grades\n");
    printf("\n\n");

    merge(a, b, c);

    printArray(c, SIZE * 2, "My sorted grades\n");
    printf("\n\n");

    return 0;
}

void printArray(int a[], int size, char *str) {
    printf("%s", str);
    for(int i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }
}

void merge(int a[], int b[], int c[]) {     // assuming arrays a & b are the same size
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < SIZE && j < SIZE) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while(i < SIZE) {
        c[k++] = a[i++];
    }

    while(j < SIZE) {
        c[k++] = b[j++];
    }
}