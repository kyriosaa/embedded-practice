#include <stdio.h>

int main() {
    char grade;

    printf("Enter your letter grade: ");
    scanf("%c", &grade);

    /*                      It's bad practice to use a lot of 'if else' statements
    if(grade == 'A') {
        printf("Well done! You did excellent!");
    } else if(grade == 'B') {
        printf("Nice one! You did good!");
    } else if(grade == 'C') {
        printf("You did okay");
    } else if(grade == 'D') {
        printf("At least it's not an F");
    } else if(grade == 'F') {
        printf("You failed miserably");
    } else {
        printf("That is not a valid letter grade");
    }
    */

   switch(grade) {
    case 'A':
        printf("Well done! You did excellent!");
        break;
    case 'B':
        printf("Nice one! You did good!");
        break;
    case 'C':
        printf("You did okay");
        break;
    case 'D':
        printf("At least it's not an F");
        break;
    case 'F':
        printf("You failed miserably");
        break;
    default:
        printf("That is not a valid letter grade");
   }

    return 0;
}