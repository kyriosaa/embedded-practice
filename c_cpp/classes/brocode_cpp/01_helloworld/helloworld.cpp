#include <iostream>

int main() {

    int x;  // declaration
    x = 5;  // assignment

    int y = 8;  // both declaration and assignment

    int sum = x + y;

    std::cout << x << "\n";
    std::cout << y << "\n";
    std::cout << sum << "\n";

    // -----------------------------------------------------

    // integer (whole number)
    int age = 23;
    int year = 2025;
    int days = 7;

    std::cout << age << "\n";

    // -----------------------------------------------------

    // double (number including decimal)
    double price = 9.99;
    double gpa = 3.1;
    double temperature = 25.1;

    std::cout << price << "\n";

    // -----------------------------------------------------

    // char (single character)
    char grade = 'A';
    char initial = 'K';
    char currency = '$';

    std::cout << currency << "\n";

    // -----------------------------------------------------

    // bool (true/false)
    bool isStudent = true;
    bool isPowered = false;
    bool isForSale = true;

    std::cout << isStudent << "\n";

    // -----------------------------------------------------

    // string (object that is a sequence of text)
    std::string day = "Friday";
    std::string food = "Tacos";
    std::string sport = "Badminton";

    std::cout << food << "\n";
    std::cout << "I want to play " << sport << "\n";
    std::cout << "You are " << age << " years old" << "\n";

    return 0;
}