#include <iostream>

int main() {
    // if statements = Do something if a condition is true.
    //                 If not, then don't do it.

    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if(age >= 18) {
        std::cout << "You are allowed to drink!";
    } else if(age < 0) {
        std::cout << "You are not born yet!";
    } else {
        std::cout << "You are not allowed to drink!";
    }

    return 0;
}