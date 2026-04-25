#include <stdio.h>

// bubble sort

void sortArray(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {

    int array[] = {9, 4, 6, 7, 3, 5, 2, 1, 8};
    int size = sizeof(array) / sizeof(array[0]);

    sortArray(array, size);
    printArray(array, size);

    return 0;
}