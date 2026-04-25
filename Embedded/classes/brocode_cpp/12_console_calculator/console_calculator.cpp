#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

double add(double num1, double num2) {
    double answer = num1 + num2;
    return answer;
}

double subtract(double num1, double num2) {
    double answer = num1 - num2;
    return answer;
}

double multiply(double num1, double num2) {
    double answer = num1 * num2;
    return answer;
}

double divide(double num1, double num2) {
    double answer = num1 / num2;
    return answer;
}

double modulo(int num1, int num2) {
    double answer = num1 % num2;
    return answer;
}

double power(double num1, double num2) {
    double answer = pow(num1, num2);
    return answer;
}

int main() {

    char operation;
    double num1;
    double num2;
    double answer;

    cout << "--- CONSOLE CALCULATOR ---\n\n";
    cout << "Please enter what operation you would like to do ( + - * / % ^ ): ";
    cin >> operation;
    
    if(operation == '^') {
        cout << "Please enter the base number: ";
        cin >> num1;
        cout << "Please enter the exponent: ";
        cin >> num2;
    } else {
        cout << "Please enter the first number: ";
        cin >> num1;
        cout << "Please enter the second number: ";
        cin >> num2;
    }

    switch(operation) {
        case '+':
            answer = add(num1, num2);
            break;
        case '-':
            answer = subtract(num1, num2);
            break;
        case '*':
            answer = multiply(num1, num2);
            break;
        case '/':
            answer = divide(num1, num2);
            break;
        case '%':
            answer = modulo(num1, num2);
            break;
        case '^':
            answer = power(num1, num2);
            break;
        default:
            return 0;
    }

    cout << num1 << " " << operation << " " << num2 << " = " << answer;

    return 0;
}