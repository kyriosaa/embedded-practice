#include <stdio.h>

#define MAX_HW 20

void readData(FILE *pointer, int data[], int *size) {
    *size = 0;
    while(fscanf(pointer, "%d", &data[*size]) == 1) {
        (*size)++;
    }
}

void printData(int data[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\t", data[i]);
        if((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

double average(int data[], int size) {
    double average = 0.0;
    for(int i = 0; i < size; i++) {
        average += data[i];
        return average / size;
    }
}

int main() {
    int sz = MAX_HW;
    FILE *inputFilePointer;
    int data[MAX_HW] = {100, 0};
    inputFilePointer = fopen("myHW", "r");
    float average = average*(data, sz);

    readData(inputFilePointer, data, &sz);
    printf("My %d homework scores are: \n", sz);
    printData(data, sz);
    printf("\nAverage score was %10f\n\n", average);
    
    fclose(inputFilePointer);   // close file

    return 0;
}