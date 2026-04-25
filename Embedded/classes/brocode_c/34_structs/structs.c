#include <stdio.h>
#include <string.h>

struct Player {
    char name[12];
    int score;
};

int main() {
    // struct = collection of related members ("variables")
    //          they can be of different data types
    //          listed under one name in a block of memory
    //          VERY SIMILAR to classes in other languages (but no methods)

    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Latte");
    player1.score = 4;

    strcpy(player2.name, "Krati");
    player2.score = 5;

    printf("%s: %d\n", player1.name, player1.score);

    printf("%s: %d\n", player2.name, player2.score);

    return 0;
}