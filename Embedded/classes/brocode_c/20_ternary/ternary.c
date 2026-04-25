#include <stdio.h>

int findMax(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int x;
    int y;

    printf("\nHello! This program finds the higher number between two numbers.\n");
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);

    if (x == y) {
        printf("\nThe numbers have the same value");
    } else {
        int max = findMax(x, y);
        printf("\nThe higher number is %d", max);
    }

    return 0;
}