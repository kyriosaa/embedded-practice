#include <stdio.h>
#include <string.h>

void enterName(char name[25]) {
    printf("\nWhat's your name?: ");
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';
}

int main() {
    // while loop = repeats a section of code possibly unlimited times
    // WHILE a condition remains true
    // a while loop might not execute at all

    char name[25];

    enterName(name);

    while(strlen(name) == 0) {
        printf("\nPlease enter your name to proceed");
        enterName(name);
    }

    printf("Hello %s", name);

    return 0;
}