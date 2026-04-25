#include <iostream>

void printInfo(const std::string &name, const int &age);

int main() {
    //  const parameter = Parameter that is effectively read-only
    //                    Code is more secure and conveys intent - useful for references and pointers

    std::string name = "Kin";
    int age = 23;

    printInfo(name, age);

    return 0;
}

void printInfo(const std::string &name, const int &age) {   // add const
    // // unable to change name and age
    // name = ' ';
    // age = 0;

    std::cout << name << "\n";
    std::cout << age << "\n";
}