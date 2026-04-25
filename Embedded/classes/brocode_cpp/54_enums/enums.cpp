#include <iostream>

enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

// size of planet in km
enum Planet {mercury = 4880, venus = 12104, earth = 12756, mars = 6794, jupiter = 142984, saturn = 108728, uranus = 51118, neptune = 49532, pluto = 2320};

int main() {

    // enums = A user-defined data type that consists of paired named-integer constants.
    //         GREAT if you have a set of potential options.

    Day today = Saturday; 
    Planet planet = mars;

    switch(today) {
        case 0:
            std::cout << "Today is Sunday!\n";
            break;
        case 1:
            std::cout << "Today is Monday!\n";
            break;
        case 2:
            std::cout << "Today is Tuesday!\n";
            break;
        case 3:
            std::cout << "Today is Wednesday!\n";
            break;
        case 4:
            std::cout << "Today is Thursday!\n";
            break;
        case 5:
            std::cout << "Today is Friday!\n";
            break;
        case 6:
            std::cout << "Today is Saturday!\n";
            break;
    }

    switch(planet) {
        case 4880:
            std::cout << "This size should be Mercury\n";
            break;
        case 12104:
            std::cout << "This size should be Venus\n";
            break;
        case 12756:
            std::cout << "This size should be Earth\n";
            break;
        case 6794:
            std::cout << "This size should be Mars\n";
            break;
        case 142984:
            std::cout << "This size should be Jupiter\n";
            break;
        case 108728:
            std::cout << "This size should be Saturn\n";
            break;
        case 51118:
            std::cout << "This size should be Uranus\n";
            break;
        case 49532:
            std::cout << "This size should be Neptune\n";
            break;
        case 2320:
            std::cout << "This size should be Pluto\n";
            break;
    }
    
    return 0;
}