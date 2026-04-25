#include <stdio.h>
#include <math.h>                           // math.h for sin() and cos()
#include <stdlib.h>                         // stdlib.h for srand() and rand()
#include <time.h>                           // time.h to make random seed

double values[5][3];                        // init a table of 3 columns and 10 rows
const int COLUMNS = 3;                      // 3 columns
const int ROWS = 5;                         // 10 rows

// function prototypes
void createTable();
void computeValue();

// main function
int main() {
    computeValue();
    createTable();

    return 0;
}

// creates a table and fills in the spaces with the computed values from computeValue()
void createTable() {
    printf("Value     |     sin     |     cos\n");

    for(int i = 0; i < ROWS; i++) {
        printf("%lf  | %lf    | %lf\n", values[i][0], values[i][1], values[i][2]);
    }
}

// generates a random input value and computes the sin and cos of said input value
void computeValue() {
    // seed for random number using current time
    srand(time(0));

    for(int i = 0; i < ROWS; i++) {
        // generates a random number between 0 and 1
        double input = rand() / (double)RAND_MAX;

       values[i][0] = input;
       values[i][1] = sin(input);
       values[i][2] = cos(input);
    }
}