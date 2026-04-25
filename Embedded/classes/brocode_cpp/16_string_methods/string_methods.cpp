#include <iostream>

int main() {

    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // .length()    = returns the length of string
    // .empty()     = checks if string is empty
    // .clear()     = clears string
    // .append()    = appends something to string
    // .at()        = returns a character at whatever index specified
    // .insert()    = inserts a character at whatever index specified
    // .find()      = finds where a specified character is within the string
    // .erase()     = erases an amount of characters starting from a specified index

    if(name.empty()) {
        std::cout << "You didn't enter your name.\n";
    } else {
        std::cout << "Name input taken.\n";

        if(name.length() > 12) {
            std::cout << "Your name cannot be over 12 characters.\n";
        } else {
            std::cout << "Welcome " << name;
        }
    }

    return 0;
}