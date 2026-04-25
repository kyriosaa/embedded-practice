#include <iostream>

int main() {

    // do while loop = Do some block of code first,
    //                 THEN repeat again if condition is true.

    int number;

    do {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while(number < 0);

    std::cout << "The number is: " << number;

    return 0;
}