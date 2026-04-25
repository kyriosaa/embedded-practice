#include <stdio.h>

#define SIZE 5

int main() {
    int grades[SIZE] = {78, 67, 92, 83, 88};
    double sum;
    double average;

    // pointer to address of sum
    double *pSum = &sum;

    printf("My grades are: ");

    for(int i = 0; i < SIZE; i++) {
        printf("%d ", grades[i]);
    }

    printf("\n");

    for(int i = 0; i < SIZE; i++) {
        sum = sum + grades[i];
    }
    average = sum / SIZE;

    printf("My average grade is: %lf", average);
    printf("\n\n");


    // %p is to show hexadecimal value of the address and %lu is the unsigned long value (they're just different ways to show the address)
    printf("The sum is at %p, or %lu and is %lf\n", pSum, pSum, *pSum);
    // 'grades' is the base address of the array and 'grades + SIZE' is the end address of the array
    printf("The grades are at %lu to %lu\n", grades, grades + SIZE);

    return 0;
}