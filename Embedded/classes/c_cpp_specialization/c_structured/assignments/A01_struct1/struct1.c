// Tells the next date of the current day
#include <stdio.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date {month month; int day;} date;

const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};                         // Specify the days in each month
const char* monthNames[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};      // Month name printing array

// --- Func declarations ---
date nextDay(date current);
void printDate(date d);
// -------------------------

int main() {
    date jan1 = {jan, 1};
    date feb28 = {feb, 28};
    date mar14 = {mar, 14};
    date oct31 = {oct, 31};
    date dec31 = {dec, 31};

    // Test jan1 -> jan2
    printf("Current day: ");
    printDate(jan1);
    date nextJan = nextDay(jan1);
    printf("Next day: ");
    printDate(nextJan);
    printf("\n");
    
    // Test feb28 -> mar1
    printf("Current day: ");
    printDate(feb28);
    date nextFeb = nextDay(feb28);
    printf("Next day: ");
    printDate(nextFeb);
    printf("\n");

    // Test mar14 -> mar15
    printf("Current day: ");
    printDate(mar14);
    date nextMar = nextDay(mar14);
    printf("Next day: ");
    printDate(nextMar);
    printf("\n");

    // Test oct31 -> nov1
    printf("Current day: ");
    printDate(oct31);
    date nextOct = nextDay(oct31);
    printf("Next day: ");
    printDate(nextOct);
    printf("\n");

    // Test dec31 -> jan1
    printf("Current day: ");
    printDate(dec31);
    date nextDec = nextDay(dec31);
    printf("Next day: ");
    printDate(nextDec);
    printf("\n");

    return 0;
}

date nextDay(date current) {
    date tomorrow;

    if(current.day < daysInMonth[current.month]) {
        // If the current.day isnt the last day of the month, then advance the day
        tomorrow.month = current.month;
        tomorrow.day = current.day + 1;
    } else {
        // If current.day is the last day of the month, check if current.month is dec.
        // If current.month == dec, make tomorrow.month = jan; else increment month by 1.
        if(current.month == dec) {
            tomorrow.month = jan;
        } else {
            tomorrow.month = current.month + 1;
        }
        // Set tomorrow.day to 1 since current.month is the last day of the month.
        tomorrow.day = 1;
    }

    return tomorrow;
}

// Prints the date
void printDate(date d) {
    printf("%s %d\n", monthNames[d.month], d.day);
}