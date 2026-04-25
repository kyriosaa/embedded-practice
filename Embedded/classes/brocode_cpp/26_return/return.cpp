#include <iostream>

double square(double number) {
    double answer = number * number;
    return answer;
}

int main() {
    // return = return a value back to the spot
    //          where you called the encompassing function

    double number = 0;

    std::cout << "Enter a value to be squared: ";
    std::cin >> number;

    std::cout << number << " squared is " << square(number);

    return 0;
}