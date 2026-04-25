#include <iostream>
using namespace :: std;

long long fact(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(void) {
    cout << "This program uses some features not in C89\n";

    for(auto i = 0; i < 16; i++) {
        cout << "Factorial of " << i << " is " << fact(i) << endl;
    }

    cout << " That's all folks!" << endl;
}