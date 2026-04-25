#include <iostream>

void recursiveWalk(int steps);
void iterativeWalk(int steps);

int main() {

    // recursion = A programming technique where a function invokes itself from within.
    //             Break a complex concept into a repeatable single step.

    // iterative VS recursive
    // advantages       = Less code, cleaner, useful for sorting and searching algorithms.
    // disadvantages    = Uses more memory, slower

    int steps;
    char choice;

    std::cout << "How many steps do you want to take?: ";
    std::cin >> steps;

    std::cout << "Do you want to walk recursively or iteratively? (r/i): ";
    std::cin >> choice;
    choice = tolower(choice);

    switch(choice) {
        case 'r':
            recursiveWalk(steps);
            break;
        case 'i':
            iterativeWalk(steps);
            break;
    }

    return 0;
}

void recursiveWalk(int steps) {
    if(steps > 0) {
        std::cout << "You take a step\n";
        recursiveWalk(steps - 1);
    }
}

void iterativeWalk(int steps) {
    for(int i = 0; i < steps; i++) {
        std::cout << "You take a step\n";
    }
}