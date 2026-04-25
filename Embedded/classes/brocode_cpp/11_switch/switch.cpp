#include <iostream>

using std::cout;
using std::cin;

int main() {
    int month;
    char grade;

    cout << "\n" << "Enter the month (1-12): ";
    cin >> month;

    switch(month) {
        case 1:
            cout << "The month is January!";
            break;
        case 2:
            cout << "The month is February!";
            break;
        case 3:
            cout << "The month is March!";
            break;
        case 4:
            cout << "The month is April!";
            break;
        case 5:
            cout << "The month is May!";
            break;
        case 6:
            cout << "The month is June!";
            break;
        case 7:
            cout << "The month is July!";
            break;
        case 8:
            cout << "The month is August!";
            break;
        case 9:
            cout << "The month is September!";
            break;
        case 10:
            cout << "The month is October!";
            break;
        case 11:
            cout << "The month is November!";
            break;
        case 12:
            cout << "The month is December!";
            break;
        default:
            cout << "Please enter a number within 1-12!";
    }

    cout << "\n" << "Enter your grade (A-F): ";
    cin >> grade;

    switch(grade) {
        case 'A':
            cout << "You did amazing!";
            break;
        case 'B':
            cout << "You did good!";
            break;
        case 'C':
            cout << "You did okay.";
            break;
        case 'D':
            cout << "You can do better.";
            break;
        case 'E':
            cout << "Is this even a real grade?";
            break;
        case 'F':
            cout << "You failed.";
            break;
        default:
            cout << "Please enter a valid grade (A-F)";
    }

    return 0;
}