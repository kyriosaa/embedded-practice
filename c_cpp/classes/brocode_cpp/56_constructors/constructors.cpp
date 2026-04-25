#include <iostream>

class Student {
    public:
        std::string name;
        int age;
        double gpa;

    // When we create a new Student object, we will automatically call this function 
    Student(std::string x, int y, double z) {
        name = x;
        age = y;
        gpa = z;
    }
};

class Car {
    public:
        std::string brand;
        std::string model;
        int year;
        std::string color;
    
    Car(std::string brand, std::string model, int year, std::string color) {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->color = color;
    }
};

int main() {

    // constructor = A special method that is automatically called when an object is instantiated.
    //               Useful for assigning values to attributes as arguments.

    Student student1("Spongebob", 25, 3.2);
    Student student2("Patrick", 27, 1.5);

    std::cout << student1.name << "\n";
    std::cout << student1.age << "\n";
    std::cout << student1.gpa << "\n";



    std::cout << "\n";



    Car car1("Chevy", "Corvette", 2022, "Silver");

    std::cout << car1.brand << "\n";
    std::cout << car1.model << "\n";
    std::cout << car1.year << "\n";
    std::cout << car1.color << "\n";

    return 0;
}