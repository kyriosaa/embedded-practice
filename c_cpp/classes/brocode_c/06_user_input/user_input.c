#include <stdio.h>
#include <string.h>

int main() {
    char name[25]; // 25 bytes
    int age;

    printf("What's your name? ");
    // scanf("%s", &name);          // scanf() wont work in this case because there might be a space in the name
    fgets(name, 25, stdin);         // fgets() includes a \n already
    name[strlen(name)-1] = '\0';    // This line gets rid of the \n

    printf("How old are you? ");
    scanf("%d", &age);

    printf("Hello %s! How are you?\n", name);
    printf("You are %d years old\n", age);

    return 0;
}