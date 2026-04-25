#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    double area;
    double radius;

    printf("This program finds the area of a circle\n");
    printf("Please enter a radius: ");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2);

    printf("The area of a circle with radius [ %.2lf ] is %.2lf", radius, area);

    return 0;
}