#include <iostream>

void printArray(int array[], int arraySize);
void bubbleSort(int array[], int arraySize);

int main() {
    int array[] = {10, 1, 4, 8, 7, 2, 9, 5, 3, 6};
    int arraySize = sizeof(array) / sizeof(array[0]);

    std::cout << "Current array is: { ";
    printArray(array, arraySize);
    std::cout << "}\n\n";

    bubbleSort(array, arraySize);

    std::cout << "Sorted array is: { ";
    printArray(array, arraySize);
    std::cout << "}\n\n";

    return 0;
}

void printArray(int array[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
}

void bubbleSort(int array[], int arraySize) {
    int temp;

    for(int i = 0; i < arraySize - 1; i++) {
        for(int j = 0; j < arraySize - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}