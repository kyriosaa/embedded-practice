#include <stdio.h>

int main() {
    // nested loops = a loop inside another loop

    int rows;
    int columns;
    char symbol;

    printf("\nEnter amount of rows: ");
    scanf("%d", &rows);
    printf("Enter amount of columns: ");
    scanf("%d", &columns);
    printf("Enter a symbol: ");
    scanf(" %c", &symbol);

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }

    return 0;
}