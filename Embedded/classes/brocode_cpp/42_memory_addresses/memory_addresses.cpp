#include <iostream>

int main() {
    // memory address = A location in memory where data is stored
    //                  A memory address can be accessed with '&' (address-of operator)

    std::string name = "Kin";
    int age = 23;
    bool student = true;

    std::cout << &name << "\n";
    std::cout << &age << "\n";
    std::cout << &student << "\n";

    return 0;
}