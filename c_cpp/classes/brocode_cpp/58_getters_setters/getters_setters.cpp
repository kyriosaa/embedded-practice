#include <iostream>

class Stove {
    private:
        int temperature = 0;
    
    public:
        int getTemperature() {      // makes the private temperature value readable
            return temperature;
        }

        void setTemperature(int temperature) {
            if(temperature < 0) {
                this->temperature = 0;
            } else if(temperature >= 10) {
                this->temperature = 10;
            } else {
                this->temperature = temperature;
            }
        }
};

int main() {

    // abstraction = Hiding unnecessary data from outside a class.
    // getter = Function that makes a private attribute READABLE
    // setter = Function that makes a private attribute WRITABLE

    Stove stove;
    
    std::cout << "The temperature setting is: " << stove.getTemperature();      // accessing and reading the private temperature value

    std::cout << "\n";

    stove.setTemperature(10000000);     // accessing and changing the private temperature value
    std::cout << "The new temperature setting is: " << stove.getTemperature();
    
    return 0;
}