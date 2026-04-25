#include <stdio.h>

long iterativeFibonacci(int n);
long recursiveFibonacci(int n);

int main() {
    int n;

    printf("Enter the length of the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nIterative: \n");
    for(int i = 0; i < n; i++) {
        printf("%ld\n", iterativeFibonacci(i));
    }

    printf("\nRecursive: \n");
    for(int i = 0; i < n; i++) {
        printf("%ld\n", recursiveFibonacci(i));
    }

    return 0;
}

long iterativeFibonacci(int n) {
    long f1 = 1;
    long f2 = 0;
    long fOld;

    for(int i = 0; i < n; i++) {
        fOld = f2;
        f2 = f2 + f1;
        f1 = fOld;
    }

    return f2;
}

long recursiveFibonacci(int n) {
    if(n <= 1) {
        return n;
    } else {
        return(recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2));
    }
}