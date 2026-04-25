#include <stdio.h>

int main() {

    // char name[] = "Kin";
    // double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0};
    // double prices[10] = {5.0, 10.0, 15.0, 25.0, 20.0};       - the array can be partially full

    double prices[5];

    prices[0] = 5.0;
    prices[1] = 10.0;
    prices[2] = 15.0;
    prices[3] = 25.0;
    prices[4] = 20.0;

    printf("$%.2lf", prices[4]);

    return 0;
}