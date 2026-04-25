#include <stdio.h>
#include <math.h>   // math.h is a library that allows for sin() to be called

int main() {
    double enteredValue;
    double sinValue;

    printf("This program gives the sine of a value between 0 and 1.\n");

    do {
        printf("Please enter a value between 0 and 1: ");
        scanf("%lf", &enteredValue);

        if(enteredValue < 0 || enteredValue > 1) {      // checks if the entered number is outside of the range of 0 & 1
            printf("The number isnt between 0 and 1! Please re-enter your number.\n");
        } else {                                        // if the number doesnt fall outside the range, then compute the sine using sin(); function
            sinValue = sin(enteredValue);
            printf("The sine of %lf is: %lf", enteredValue, sinValue);
            break;
        }
    } while (enteredValue < 0 || enteredValue > 1);     // if the number is outside of the range of 0 & 1, then repeat the loop until it falls within range

    return 0;
}