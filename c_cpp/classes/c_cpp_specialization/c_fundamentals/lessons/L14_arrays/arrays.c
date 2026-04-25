#include <stdio.h>

#define SIZE 5

int main() {
    int grades[SIZE] = {78, 67, 92, 83, 88};
    double sum;
    double average;

    printf("My grades are: ");

    for(int i = 0; i < SIZE; i++) {
        printf("%d ", grades[i]);
    }

    printf("\n\n");

    for(int i = 0; i < SIZE; i++) {
        sum = sum + grades[i];
    }

    average = sum / SIZE;

    printf("My average grade is: %.2lf", average);

    return 0;
}