#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // pseudo random numbers = A set of values or elements that are statistically random
    //                         (Don't use these for any sort of cryptographic security tho)

    srand(time(0));

    int number1 = (rand() % 20) + 1;        // Use modulus (%) to get the remainder
    int number2 = (rand() % 20) + 1;        // and + 1 since the starting number is 0.
    int number3 = (rand() % 20) + 1;        // So ((rand() % 20) + 1) will give an output from 1-20

    printf("%d\n", number1);
    printf("%d\n", number2);
    printf("%d\n", number3);

    return 0;
}