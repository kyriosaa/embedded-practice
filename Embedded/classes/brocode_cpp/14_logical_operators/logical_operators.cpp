#include <iostream>

int main() {
    // && = checks if two conditions are true
    // || = checks if at least one of two conditions is true
    // !  = revverses the logical state of its operand

    int temp;
    int age;
    bool isSunny;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;
    temp > 0 && temp < 30 ? std::cout << "The temperature is good\n" : std::cout << "The temperature is bad\n";

    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << (age <= 0 || age >= 120 ? "You are probably dead!\n" : "You are probably alive!\n");

    isSunny ? std::cout << "It is sunny outside\n" : std::cout << "It is cloudy outside\n";

    return 0;
}