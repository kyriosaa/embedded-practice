#include <iostream>

void bakePizza() {
    std::cout << "Here is your pizza!\n";
}

void bakePizza(std::string topping1) {
    std::cout << "Here is your " << topping1 << " pizza!\n";
}

void bakePizza(std::string topping1, std::string topping2) {
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!\n";
}

int main() {

    std::string topping1 = "pepperoni";
    std::string topping2 = "anchovies";

    bakePizza();
    bakePizza(topping1);
    bakePizza(topping1, topping2);
    
    return 0;
}