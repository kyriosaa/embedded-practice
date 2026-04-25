#include <stdio.h>

void birthday(char name[], int age) {
    printf("\nHappy birthday %s", name);
    printf("\nYou are %d years old!", age);
}

int main() {
    char name[] = "Kin";
    int age = 22;

    printf("\nEnter your name: ");
    scanf("%s", &name);
    printf("\nEnter your age: ");
    scanf("%d", &age);

    birthday(name, age);

    return 0;
}