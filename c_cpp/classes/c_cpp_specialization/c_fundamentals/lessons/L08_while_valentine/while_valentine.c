#include <stdio.h>

int main() {
    int loveScore;

    printf("How much do you love me on a scale of 1-10?: ");
    scanf("%d", &loveScore);

    printf("I love you ");
    while(loveScore > 0) {
        printf("very ");
        loveScore--;
    }
    printf("much!");

    return 0;
}