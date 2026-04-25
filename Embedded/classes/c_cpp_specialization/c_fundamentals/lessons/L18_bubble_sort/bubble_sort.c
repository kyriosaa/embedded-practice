#include <stdio.h>

void printInitArray();
void sortArray();
void printSortedArray();

int main() {
    int grades[] = {78, 67, 92, 83, 88};
    int size = sizeof(grades) / sizeof(grades[0]);

    printInitArray(size, grades);
    sortArray(size, grades);
    printSortedArray(size, grades);

    return 0;
}

void printInitArray(int size, int grades[]) {
    printf("My unsorted grades are: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n\n");
}

void sortArray(int size, int grades[]) {
    int temp;
    // Outer loop ensures the sorting process is repeated enough times
    // to guarantee that all elements are sorted.
    for(int i = 0; i < size - 1; i++) {
        // Inner loop compares each pair of adjacent elements and swaps them if
        // they are in the wrong order.
        for(int j = 0; j < size - i - 1; j++) {
            if(grades[j] > grades[j + 1]) {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }
}

void printSortedArray(int size, int grades[]) {
    printf("My bubble sorted grades are: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", grades[i]);
    }
}