#include <stdio.h>

int main() {
    struct pointer{
        double x;
        double y;
    } p1 = {10, 20};

    struct pointer* ptr = &p1;

    printf("%lf", ptr -> x);
    return 0;
}