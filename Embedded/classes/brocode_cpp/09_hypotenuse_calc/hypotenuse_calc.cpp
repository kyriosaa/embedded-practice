#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::pow;

double findHypotenuse(double num1, double num2) {
    double answer = sqrt((pow(num1, 2) + pow(num2, 2)));
    return answer;
}

int main() {
    double num1;
    double num2;

    cout << "--- HYPOTENUSE CALCULATOR ---\n\n";
    cout << "Please input length: ";
    cin >> num1;
    cout << "Please input width: ";
    cin >> num2;

    cout << "The hypotenuse of " << num1 << " & " << num2 << " is " << findHypotenuse(num1, num2);

    return 0;
}