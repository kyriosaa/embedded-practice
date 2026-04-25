#include <iostream>

int main() {
    // array = A data structure that can hold multiple values.
    //         Values are accessed by an index number.
    //         "Kind of like a variable that holds multiple values"
    //         "Or like a box with multiple values"

    std::string car[] = {"Corvette", "Mustang", "Camry"};

    std::cout << car << "\n";       // memory address
    std::cout << car[0] << "\n";    // Corvette
    std::cout << car[1] << "\n";    // Mustang
    std::cout << car[2] << "\n";    // Camry

    return 0;
}