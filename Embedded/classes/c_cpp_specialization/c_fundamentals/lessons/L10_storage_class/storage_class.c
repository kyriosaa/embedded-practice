#include <stdio.h>

int reps = 0;

void f();

int main() {
    int i = 1;
    const int LIMIT = 10;

    for(i = 1; i < LIMIT; i++) {
        printf("i local = %d, reps global = %d\n", i, reps);
        f();
    }

    return 0;
}

void f() {
    static int called = 0;
    printf("f called %d\n", called);
    called++;
    reps = reps + called;
}