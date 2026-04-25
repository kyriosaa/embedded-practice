#include <stdio.h>
#include <string.h>

int main() {
    char cars[][10] = {"Mustang", "Corvette", "Camaro"};

    strcpy(cars[0], "Civic");       // strcpy is needed if you want to change a string

    int arraySize = sizeof(cars) / sizeof(cars[0]);

    for(int i = 0; i < arraySize; i++) {
        printf("\n%s", cars[i]);
    }

    return 0; 
}