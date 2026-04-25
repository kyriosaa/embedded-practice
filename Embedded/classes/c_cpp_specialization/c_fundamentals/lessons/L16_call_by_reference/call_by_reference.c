#include <stdio.h>

void swap();
void swapReference();

int main() {
    int a = 2;
    int b = 5;
    int temp;

    swap(a, b, temp);

    printf("Values after using swap(): a = %d   b = %d\n", a, b);

    swapReference(&a, &b, temp);

    printf("Values after using swapReference(): a = %d   b = %d\n", a, b);

    return 0;
}

// In C, arguments are passed to functions by value, meaning that a copy of each variable is made.
// In this swap() function, when you pass a, b, and temp, the function only works with copies.
// Any changes made inside the function do not affect the original variables in main().
void swap(int a, int b, int temp) {
    temp = a;
    a = b;
    b = temp;
}

// On the other hand, swapReference() accepts pointers (int *a and int *b) as parameters.
// When you call this function with &a and &b, you pass the memory addresses of a and b. 
// Inside the function, dereferencing (*a and *b) allows you to access and modify the actual variables in main.
// This is why the swapping operation in swapReference() works—the changes are applied directly to the original variables.
void swapReference(int *a, int *b, int temp) {
    temp = *a;
    *a = *b;
    *b = temp;
}
