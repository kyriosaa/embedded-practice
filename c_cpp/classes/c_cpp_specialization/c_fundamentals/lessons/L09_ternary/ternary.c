#include <stdio.h>

int main() {
    int speed;
    
    printf("Enter your speed as an integer: ");
    scanf("%d", &speed);

    speed = (speed <= 65) ? (65):(speed <= 70) ? (70):(90);

    switch(speed) {
        case 65:
            printf("No speeding ticket\n");
            break;
        case 70:
            printf("Speeding ticket");
            break;
        case 90:
            printf("Excessive speeding ticket");
            break;
        default:
            printf("Invalid input");
    }

    return 0;
}