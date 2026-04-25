#include <iostream>

int main() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 10; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}