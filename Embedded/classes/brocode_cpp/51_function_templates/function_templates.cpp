#include <iostream>

template <typename T, typename U>

auto max(T x, U y) {                // (T/U) can accept two different types. Auto will make compiler auto-decide what type should be returned.
    return (x > y) ? x : y;
}

int main() {

    // function template = Describes what a function looks like. 
    //                     Can be used to generate as many overloaded functions as needed, each using different data types.

    std::cout << max(1, 2) << "\n";
    std::cout << max(1.1, 2.1) << "\n";
    std::cout << max('1', '2') << "\n";

    return 0;
}