#include <iostream>

class Pizza {
    public:
        std::string topping1;
        std::string topping2;

    Pizza() {
        // for no toppings
    }
    Pizza(std::string topping1) {
        this->topping1 = topping1;
    }
    Pizza(std::string topping1, std::string topping2) {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};

int main() {

    // overloaded constructors = Multiple constructors with the same name but different parameters.
    //                           Allows for varying arguments when instantiating an object.

    Pizza pizza1("Pepperoni");
    Pizza pizza2("Mushrooms", "Peppers");
    Pizza pizza3;

    std::cout << pizza1.topping1 << "\n\n";

    std::cout << pizza2.topping1 << "\n";
    std::cout << pizza2.topping2 << "\n\n";

    return 0;
}