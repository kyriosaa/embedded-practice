#include <stdio.h>

int main() {
    // break = exits a loop/switch
    // continue = skips the rest of the code & forces the next iteration of the loop

    for(int i = 1; i <= 20; i++) {
        if(i == 13) {
            continue;
        } else {
            printf("\n%d", i);
        }
    }

    return 0;
}