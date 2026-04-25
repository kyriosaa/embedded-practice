#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int MIN = 1;
    const int MAX = 10;
    int guess;
    int guesses;
    int answer;

    // uses current time as seed
    srand(time(0));

    // generate random number between MIX-MAX
    answer = (rand() % MAX) + MIN;

    do {
        printf("Guess a number: ");
        scanf("%d", &guess);

        if(guess > answer) {
            printf("The guess is too high!\n");
        } else if(guess < answer) {
            printf("The guess is too low!\n");
        } else {
            printf("Correct!\n");
        }
        guesses++;

    } while(guess != answer);

    printf("\n*****************************\n");
    printf("Answer: %d\n", answer);
    printf("# of guesses: %d\n", guesses);
    printf("*****************************");

    return 0;
}