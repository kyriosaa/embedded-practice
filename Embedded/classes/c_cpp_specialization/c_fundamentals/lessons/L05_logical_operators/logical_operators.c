#include <stdio.h>
#include <ctype.h>

int main() {
    char weather;
    char outside;

    do {
        printf("Is it raining? (Y/N): ");
        scanf(" %c", &weather);
        weather = toupper(weather);

        if(weather == 'Y') {
            break;
        } else if(weather == 'N') {
            break;
        } else {
            printf("Invalid input!\n\n");
        }

    } while(weather != 'Y' || weather != 'N');

    do {
        printf("Are you outside? (Y/N): ");
        scanf(" %c", &outside);
        outside = toupper(outside);

        if(outside == 'Y') {
            break;
        } else if(outside == 'N') {
            break;
        } else {
            printf("Invalid input!\n\n");
        }

    } while(outside != 'Y' || outside != 'N');

    
    
    if(weather == 'Y' && outside == 'Y') {
        printf("Please use an umbrella.");
    } else {
        printf("Dress normally.");
    }

    return 0;
}