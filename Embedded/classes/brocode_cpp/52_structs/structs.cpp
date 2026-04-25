#include <iostream>

// kinda like an array but you can put multiple data types inside
struct student {
    std::string name;
    double gpa;
    bool isEnrolled;
};

int main() {

    // struct = A structure that group related variables under one name.
    //          Structs can contain many different data types (string, int, double, bool, etc.)
    //          Variables in a struct are known as "members".
    //          Members can be accessed with . "Class Member Access Operator".

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.isEnrolled = true;

    student student2;
    student2.name = "Patrick";
    student2.gpa = 1.8;
    student2.isEnrolled = true;

    std::cout << student1.name << "\n";
    std::cout << student1.gpa << "\n";
    std::cout << student1.isEnrolled << "\n";

    std::cout << student2.name << "\n";
    std::cout << student2.gpa << "\n";
    std::cout << student2.isEnrolled << "\n";

    return 0;
}