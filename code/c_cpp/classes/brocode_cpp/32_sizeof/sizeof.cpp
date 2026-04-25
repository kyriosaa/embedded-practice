#include <iostream>

int main() {
    // sizeof() = Determines the size in bytes of a: variable, data type, class, objects, etc.
    
    double gpa = 3.2;
    std::string name = "Bob";
    bool isStudent = true;

    char grade = 'F';
    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    std::string students[] = {"Spongebob", "Patrick", "Squidward"};

    // ------------------------------------------------------------------------------------------------

    std::cout << sizeof(gpa) << " bytes\n";         // 8 bytes
    std::cout << sizeof(name) << " bytes\n";        // 32 bytes (never changes even if string gets long)
    std::cout << sizeof(isStudent) << " bytes\n";   

    std::cout << sizeof(grade) << " bytes\n";       // 1 byte
    std::cout << sizeof(grades) << " bytes\n";      // 5 bytes (because there are 5 characters in this array)
    std::cout << sizeof(grades) / sizeof(char) << " elements\n";
    
    std::cout << sizeof(students) / sizeof(std::string) << " elements\n";

    return 0;
}