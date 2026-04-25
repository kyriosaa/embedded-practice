#include <iostream>

int main() {
    std::string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};
    int studentsSize = sizeof(students) / sizeof(std::string);

    for(int i = 0; i < studentsSize; i++) {
        std::cout << students[i] << "\n";
    }

    return 0;
}