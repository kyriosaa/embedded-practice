#include <iostream>

int main() {
    // type conversion = conversion of a value of one data type to another
    //                   Implicit = automatic
    //                   Explicit = precede value with new data type 


    double x = (int)3.14;  // convert 3.14 to an int and store it inside a double

    std::cout << x;
    std::cout << (char)100 << "\n";    // convert 100 to a char and print

    // -------------------------------------------------------------------------------

    int correct = 8;
    int questions = 10;

    // double score = correct / questions * 100;    // this won't work because we are doing int math on a double data type
    double score = correct / (double)questions * 100;

    std::cout << score << "%\n";

    return 0;
}