#include <iostream>

struct Car {
    std::string model;
    int year;
    std::string color;
    bool isWorking = true;
};

void printCar(Car &car);
void paintCar(Car &car, std::string color);

int main() {

    Car car1;
    Car car2;

    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "Red";

    car2.model = "Corvette";
    car2.year = 2024;
    car2.color = "Blue";

    paintCar(car1, "Silver");
    std::cout << &car1 << "\n";
    printCar(car1);

    std::cout << "\n";
    
    std::cout << &car2 << "\n";
    printCar(car2);
    
    return 0;
}

void printCar(Car &car) {
    std::cout << &car << "\n";
    std::cout << car.model << "\n";
    std::cout << car.year << "\n";
    std::cout << car.color << "\n";
    std::cout << car.isWorking << "\n";
}

void paintCar(Car &car, std::string color) {
    car.color = color;
}