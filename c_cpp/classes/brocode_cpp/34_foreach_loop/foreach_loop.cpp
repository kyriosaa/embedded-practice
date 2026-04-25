#include <iostream>

int main() {
    // foreach loop = Loop that eases the traversal over an iterable data set

    std::string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};
    int grades[] = {65, 71, 93, 84};

    for(std::string student : students) {
        std::cout << student << "\n";
    }

    std::cout << "\n\n";

    for(int grade : grades) {
        std::cout << grade << "\n";
    }

    return 0;
}