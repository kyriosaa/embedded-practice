#include <iostream>

int main() {

    int num = 0;
    int guess = 0;
    int tries = 0;

    srand(time(0));
    num = rand() % 100 + 1;

    std::cout << "----- Number Guessing Game -----\n\n";
    
    do {
        std::cout << "Enter a guess between 1-100: ";
        std::cin >> guess;
        tries++;
        
        if(guess > num) {
            std::cout << "Too high!\n";
        } else if(guess < num) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "Correct! You win!\n";
            std::cout << "# of tries: " << tries;
        }
        
    } while(guess != num);
    
    std::cout << "\n\n--------------------------------";

    return 0;
}