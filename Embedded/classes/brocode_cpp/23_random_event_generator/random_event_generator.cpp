#include <iostream>
#include <ctime>

int main() {
    srand(time(0));

    int randNum = rand() % 5 + 1;

    switch(randNum) {
        case 1:
            std::cout << "You win a bumper sticker!\n";
            break;
        case 2:
            std::cout << "You win a water gun!\n";
            break;
        case 3:
            std::cout << "You win a t-shirt!\n";
            break;
        case 4:
            std::cout << "You win a doll!\n";
            break;
        case 5:
            std::cout << "You win a new iPhone Pro Max Ultra Plus 18!\n";
            break;
    }

    return 0;
}