#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18 && age < 100) {
        printf("You are now signed up!");
    } else if(age <= 0) {
        printf("You haven't been born yet!");
    } else if(age >= 100) {
        printf("You are too old!");
    } else {
        printf("You need to be at least 18 years old!");
    }

    return 0;
}