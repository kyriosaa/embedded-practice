// miles to kilometers

#include <iostream>
using namespace :: std;
const double milesToKilometers = 1.609;

inline double convert(int miles) {
    return (miles * milesToKilometers);
}

int main(void) {
    int miles = 1;

    while(miles != 0) {
        cout << "Input distance in miles or 0 to terminate: ";
        cin >> miles;
        cout << "\nDistance is " << convert(miles) << " km." << endl;
    }
    cout << endl;
}