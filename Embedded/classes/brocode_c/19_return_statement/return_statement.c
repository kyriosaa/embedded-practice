#include <stdio.h>
#include <math.h>

float square(float chosenNumber) {
    double result = pow(chosenNumber, 2);
    return result;
}

int main() {
    float chosenNumber;
    float result;

    printf("What number would you like to square? ");
    scanf("%f", &chosenNumber);

    result = square(chosenNumber);
    printf("%.1f squared is: %.1f", chosenNumber, result);

    return 0;
}