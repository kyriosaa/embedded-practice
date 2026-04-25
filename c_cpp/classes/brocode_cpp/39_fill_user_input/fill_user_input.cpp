#include <iostream>

int main() {
    std::string foods[5];
    int size = sizeof(foods) / sizeof(foods[0]);
    std::string temp;

    for(int i = 0; i < size; i++) {
        std::cout << "Enter your favorite food #" << i + 1 << " or 'q' to quit: ";
        std::getline(std::cin, temp);

        if(temp == "q") {
            break;
        } else {
            foods[i] = temp;
        }
    }

    std::cout << "You like the following foods:\n";

    for(int i = 0; !foods[i].empty(); i++) {
        std::cout << foods[i] << "\n";
    }

    return 0;
}