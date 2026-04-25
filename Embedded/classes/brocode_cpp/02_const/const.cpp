#include <iostream>

int main() {
    // 'const' specifies that a variable's value is constant
    // tells the compiler to prevent anything from modifying it
    // (read-only)

    const double PI = 3.14159;
    // PI = 235443;     You cannot change PI anymore because it is const
    double radius = 10;
    double circumference = 2 * PI * radius;

    std::cout << circumference << " cm";

    return 0;
}