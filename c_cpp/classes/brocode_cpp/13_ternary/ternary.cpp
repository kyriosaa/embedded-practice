#include <iostream>

int main() {
    // ternary operator ?: = Replacement to an if/else statement.
    //                       Condition ? expression1 : expression2



    // -------------------------------------------------------------------
    int grade = 75;

    // if(grade >= 60) {
    //     std::cout << "You pass!";
    // } else {
    //     std::cout << "You fail!";
    // }

    grade >= 60 ? std::cout << "You pass!\n" : std::cout << "You fail!\n";
    // -------------------------------------------------------------------



    // -------------------------------------------------------------------
    int number = 9;
    number % 2 ? std::cout << "ODD\n" : std::cout << "EVEN\n";
    // -------------------------------------------------------------------



    // -------------------------------------------------------------------
    bool isHungry = true;
    isHungry ? std::cout << "You are hungry\n" : std::cout << "You are full\n";
    std::cout << (isHungry ? "You are hungry\n" : "You are full\n");
    // -------------------------------------------------------------------

    return 0;
}