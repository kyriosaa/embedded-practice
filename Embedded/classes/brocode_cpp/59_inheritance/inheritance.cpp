#include <iostream>

class Animal {
    public:
        bool isAlive = true;

    void eat() {
        std::cout << "This animal is eating\n";
    }
};

class Dog : public Animal {
    public:

    void bark() {
        std::cout << "The dog goes woof!\n";
    }
};

class Cat : public Animal {
    public:

    void meow() {
        std::cout << "The cat goes meow!\n";
    }
};

int main() {

    // inheritance = A class can receive attributes and methods from another class.
    //               Children classes inherit from a Parent class.
    //               Helps to reuse similar code found within multiple classes.

    Dog dog;
    std::cout << dog.isAlive << "\n";
    dog.eat();
    dog.bark();

    std::cout << "\n";

    Cat cat;
    std::cout << cat.isAlive << "\n";
    // cat.bark();  // doesn't work bcs bark() is only in the dog class
    cat.eat();
    cat.meow();

    return 0;
}