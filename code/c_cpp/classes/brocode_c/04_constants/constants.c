#include <stdio.h>

int main() {
    // constant = fixed value that cannot be altered by the program during its execution

    const float PI = 3.14159;

    PI = 420.69; // trying to change the const value causes an error

    printf("%f\n", PI);

    return 0;
}