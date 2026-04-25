#include <iostream>

using std::cout;
using std::cin;
using std::string;

void birthdaySong(string name, int age) {
    cout << "\n";
    cout << "Happy birthday to " << name << "\n";
    cout << "Happy birthday to " << name << "\n";
    cout << "Happy birthday, happy birthday\n";
    cout << "Happy birthday to " << name << "\n\n";
    cout << "You are " << age << " years old!\n";
}

int main() {

    // function = A block of reusable code

    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    birthdaySong(name, age);

    return 0;
}