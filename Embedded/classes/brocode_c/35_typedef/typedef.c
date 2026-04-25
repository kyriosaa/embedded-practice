#include <stdio.h>
#include <string.h>

// typedef char user[25];

typedef struct {
    char name[25];
    char password[12];
    int id;
} User;

int main() {
    // typedef = reserved keyword that gives an existing datatype a "nickname"

    User user1 = {"Kin", "password123", 123456789};
    User user2 = {"Latte", "password321", 987654321};

    printf("User: %s\n", user1.name);
    printf("Pass: %s\n", user1.password);
    printf("ID: %d\n", user1.id);
    printf("\n");
    printf("User: %s\n", user2.name);
    printf("Pass: %s\n", user2.password);
    printf("ID: %d\n", user2.id);
    printf("\n");

    return 0;
}