#include <stdio.h>

#define SIZE 5

double averageGrades();
void printGrades();

int main() {
    int grades[SIZE] = {78, 67, 92, 83, 88};
    double average = averageGrades(grades);

    printGrades(grades);
    printf("\n\n");
    printf("My average is %.2f\n\n", average);
    
    return 0;
}

double averageGrades(int grades[]) {
    double sum;

    for(int i = 0; i < SIZE; i++) {
        sum = sum + grades[i];
    }
    sum = sum / SIZE;
    return sum;
}

void printGrades(int grades[]) {
    printf("I have %d grades: ", SIZE);
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", grades[i]);
    }
}