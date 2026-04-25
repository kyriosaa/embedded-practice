#include <stdio.h>

void hello(char[], int); // function prototype

int main() {
    char name[] = "User";
    int age = 0;

    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Enter your age: ");
    scanf("%d", &age);

    hello(name, age);

    return 0;
}

void hello(char name[], int age) {
    printf("\nHello %s!", name);
    printf("\nYou are %d years old!", age);
}