#include <iostream>

int globalNum = 4;

void printLocal() {
    int localNum = 2;
    std::cout << localNum << "\n";
}

void printGlobal() {
    std::cout << globalNum << "\n";
}

int main() {
    // local variables  = declared inside a function or block {}
    // global variables = declared outside of all functions

    printLocal();
    printGlobal();

    return 0;
}