#include <iostream>
#include <cmath>

int main() {

    double num1 = 3;
    double num2 = 4;
    double num3 = 3.14159;

    // min & max
    double a = std::max(num1, num2);
    double b = std::min(num1, num2);

    // power
    double c = pow(num1, num2);

    // square root
    double d = sqrt(num2);

    // absolute value
    double e = abs(-num2);

    // round
    double f = round(num3);

    // ceiling & floor
    double g = ceil(num3);
    double h = floor(num3);

    std::cout << "\n" << a;
    std::cout << "\n" << b;
    std::cout << "\n" << c;
    std::cout << "\n" << d;
    std::cout << "\n" << e;
    std::cout << "\n" << f;
    std::cout << "\n" << g;
    std::cout << "\n" << h;

    return 0;
}