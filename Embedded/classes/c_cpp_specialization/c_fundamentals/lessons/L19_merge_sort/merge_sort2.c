#include <stdio.h>

#define SIZE 8

void printArray();
void merge();
void mergeSort();

int main() {
    int a[SIZE] = {99, 82, 74, 85, 92, 67, 76, 49};
    printArray(a, SIZE, "My grades\n");
    printf("\n\n");
    mergeSort(a, SIZE);
    printArray(a, SIZE, "My sorted grades\n");
    printf("\n\n");

    return 0;
}

void printArray(int a[], int size, char *str) {
    printf("%s", str);
    for(int i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }
}

void merge(int a[], int b[], int c[], int size) {
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < size && j < size) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while(i < size) {
        c[k++] = a[i++];
    }
    while(j < size) {
        c[k++] = b[j++];
    }
}

void mergeSort(int array[], int size) {
    int w[SIZE];

    for(int k = 1; k < size; k *= 2) {
        for(int j = 0; j < size - k; j += 2 * k) {
            merge(array + j, array + j + k, w + j, k);
        }
        for(int j = 0; j < size; j++) {
            array[j] = w[j];
        }
    }
}