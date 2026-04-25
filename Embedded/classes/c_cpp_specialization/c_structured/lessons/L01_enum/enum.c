#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat}; // declare type
typedef enum day day;

void printDay(day d) {
    switch(d) {
        case sun:
            printf("Sunday\n");
            break;
        case mon:
            printf("Monday\n");
            break;
        case tue:
            printf("Tuesday\n");
            break;
        case wed:    
            printf("Wednesday\n");
            break;
        case thu:
            printf("Thursday\n");
            break;
        case fri:
            printf("Friday\n");
            break;
        case sat:    
            printf("Saturday\n");
            break;
        default:
            printf("%d is an error\n", d);
            break;
    }
}

enum day nextDay(day d) {
    return (d + 1) % 7;  // once values go over 6, mod back within 0-6
}

int main() {
    day today = wed;
    printDay(today);
    printf("\n\n");
    printDay(7);
    printf("\n\n");
    printDay(nextDay(today));
    printf("\n\n");
    return 0;
}