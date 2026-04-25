#include <stdio.h>

long iterativeFactorial(long n);
long recursiveFactorial(long n);

int main() {
    long n;

    printf("Compute a factorial up to number n\n");
    printf("n = ");
    scanf("%ld", &n);

    printf("%ld! is %ld\n", n, iterativeFactorial(n));
    printf("%ld! is %ld\n", n, recursiveFactorial(n));

    return 0;
}

long iterativeFactorial(long n) {
    long result = 1;

    for(int i = 1; i <= n; i++) {
        result *= i;    // result = result * i
    }
    return result;
}

long recursiveFactorial(long n) {
    if(n == 1) {
        return 1;
    } else {
        return(recursiveFactorial(n - 1) * n);
    }
}