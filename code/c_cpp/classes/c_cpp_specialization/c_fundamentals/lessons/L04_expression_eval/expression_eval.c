#include <stdio.h>

int main() {
    int a = 5;
    int b = 7;
    int c = 0;
    int d = 0;

    c = a + b;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    c = a - b;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    c = a * b;
    d = b / a;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    c = a % b;
    d = -b - a;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    return 0;
}