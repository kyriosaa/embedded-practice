#include <stdio.h>

int main() {
    double prices[] = {5.00, 12.25, 49.99, 75.00, 99.99};

    int arrayLength = sizeof(prices) / sizeof(prices[0]); // sizeof() checks the size of the array. So we need to divide it by the size of the individual data type.

    for(int i = 0; i < arrayLength; i++) {

        printf("\n$%.2lf", prices[i]);
    }

    return 0;
}