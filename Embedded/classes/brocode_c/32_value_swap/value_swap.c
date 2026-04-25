#include <stdio.h>
#include <string.h>

int main() {
    char x[15] = "water";           // make the two arrays the same size so all characters are moved over when using strcpy()
    char y[15] = "lemonade";
    char temp[15];

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
    
    printf("\nx = %s", x);
    printf("\ny = %s", y);

    return 0;
}