// C = (F - 32)/1.8
#include <stdio.h>

int main() {
    int fahrenheit;
    int celsius;

    printf("This program converts fahrenheit into celsius\n");
    printf("Please enter a temperature in (F): ");
    scanf("%d", &fahrenheit);

    celsius = (fahrenheit - 32) / 1.8;

    printf("The temperature in (C) is %d", celsius);

    return 0;
}