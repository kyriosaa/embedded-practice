#include <stdio.h>

void countdown(int time);

int main() {
    int time = 10;
    countdown(time);
    return 0;
}

void countdown(int time) {
    if(time == 0) {
        printf("Blast off!\n");
    } else {
        printf("Time is %d\n", time);
        countdown(time - 1);
    }
}

// tbh this thing can be done better and safer using a for loop. But this program is only for learning purposes anyways