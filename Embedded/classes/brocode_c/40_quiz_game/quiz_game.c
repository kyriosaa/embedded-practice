#include <stdio.h>
#include <ctype.h>

// ok i used some pointers in this program bcs i wanted to make it complicated for myself for no real reason

void guessFunc(char *guess) {
    printf("\nGuess: ");
    scanf(" %c", guess);
    *guess = toupper(*guess);
    printf("\n");
}

int main() {
    char questions[][100] = {"1. What year did the C language debut?: ",
                             "2. Who is credited with creating C?: ",
                             "3. What is the predecessor of C?: "};
    
    char options[][100] = {"(A) 1969", "(B) 1972", "(C) 1975", "(D) 1999",
                           "(A) Dennis Ritchie", "(B) Nikola Tesla", "(C) John Carmack", "(D) Doc Brown",
                           "(A) Objective C", "(B) B", "(C) C++", "(D) C#"};

    char answers[3] = {'B', 'A', 'B'};
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score;

    printf("\n-------------- QUIZ GAME --------------\n\n");

    
    for(int i = 0; i < numberOfQuestions; i++) {
        printf("***************************************\n");
        printf("%s\n", questions[i]);

        for(int j = (i * 4); j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
        }
        
        guessFunc(&guess);

        if(guess == answers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect!\n");
        }

        printf("***************************************\n\n");
    }
    
    printf("Final Score: %d", score);

    return 0;
}