#include <iostream>

int main() {
    // break = Break out of a loop
    // continue = Skip current iteration

    for(int i = 1; i <= 20; i++) {
        if(i == 13) {
            continue;   // skips 13
        } else if(i == 19) {
            break;      // breaks the loop
        }
        std::cout << i << "\n";
    }

    return 0;
}