#include <iostream>

int main() {
    // fill() = Fills a range of elements with a specified value
    //          fill(begin, end, value)

    const int ARRAY_SIZE = 99;

    std::string foods[ARRAY_SIZE];

    fill(foods, foods + (ARRAY_SIZE / 3), "Tacos");
    fill(foods + (ARRAY_SIZE / 3), foods + (ARRAY_SIZE / 3) * 2, "Pizza");
    fill(foods + (ARRAY_SIZE / 3) * 2, foods + ARRAY_SIZE, "Nachos");

    for(std::string food : foods) {
        std::cout << food << "\n";
    }

    return 0;
}