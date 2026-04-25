#include <stdio.h>

int main() {
    int speed;

    printf("Enter your speed: ");
    scanf("%d", &speed);

    if(speed < 65 && speed > 0) {
        printf("No speeding ticket");
    } else if(speed < 1) {
        printf("Your car isn't even moving!");
    } else {
        printf("You get a free speeding ticket!");
    }

    return 0;
}