#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main() {

    double temp;
    char unit;

    cout << "----- Temperature Conversion Program -----\n\n";

    do {
        cout << "F = Fahrenheit\n";
        cout << "C = Celsius\n";
        cout << "What unit would you like to convert to? ";
        cin >> unit;
        unit = toupper(unit);

        if(unit != 'F' && unit != 'C') {
            cout << "Please enter a valid unit.\n\n";
        }

    } while(unit != 'F' && unit != 'C');

    if(unit == 'F') {
        cout << "Enter the temperature in Celsius: ";
        cin >> temp;

        temp = (1.8 * temp) + 32.0;
        cout << "Temperature is " << temp << " F";
    } else if(unit == 'C') {
        cout << "Enter the temperature in Fahrenheit: ";
        cin >> temp;

        temp = (temp - 32) / 1.8;
        cout << "Temperature is " << temp << " C";
    }

    cout << "\n\n------------------------------------------";

    return 0;
}