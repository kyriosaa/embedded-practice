#include <stdio.h>

int main() {
    // memory = an array of bytes within RAM
    // memory block = a single unit (byte) within memory, used to hold some value
    // memory address = the address of where a memory block is located

    char a = 'A';
    short b = 'B';
    int c = 'C';
    double d = 'D';

    char e[1];
    short f[1];
    double g[10];

    printf("%p\n", &a);
    printf("%d bytes\n\n", sizeof(a));

    printf("%p\n", &b);
    printf("%d bytes\n\n", sizeof(b));

    printf("%p\n", &c);
    printf("%d bytes\n\n", sizeof(c));

    printf("%p\n", &d);
    printf("%d bytes\n\n", sizeof(d));

    printf("-------------------------\n\n");

    printf("%p\n", &e);
    printf("%d bytes\n\n", sizeof(e));

    printf("%p\n", &f);
    printf("%d bytes\n\n", sizeof(f));

    printf("%p\n", &g);
    printf("%d bytes\n\n", sizeof(g));

    return 0;
}