#include <stdio.h>
#include <stdbool.h>

int main () {
    int x; // declaration
    x = 123; // initialization
    int y = 456; // declaration + initialization

    int age = 22; 
    float gpa = 3.19;
    char grade = 'A'; 
    char name[] = "Kin"; 

    printf("Hello %s!\n", name);
    printf("You are %d years old\n", age);
    printf("Your average grade is \"%c\"\n", grade);
    printf("Your GPA is %f\n", gpa);

    /*-------------------------------------------------------------------------*/

    char a = 'A';                   // single character             %c
    char b[] = "Bro";               // array of characters          %s

    float c = 3.141592;             // 4 bytes (32 bits of precision) 6 - 7 digits    %f
    double d = 3.141592653589793;   // 8 bytes (64 bits of precision) 15 - 16 digits  %lf

    bool e = true;                  // 1 byte (true or false)       %d

    char f = 120;                   // 1 byte (-128 - +127)         %d or %c
    unsigned char g = 255;          // 1 byte (0 - +255)            %d or %c

    short h = 32767;                // 2 bytes (-32,768 - +32,767)  %d
    unsigned short i = 65535;       // 2 bytes (0 - +65,535)        %d

    int j = 2147483647;             // 4 bytes (-2,147,483,648 - +2,147,483,647)  %d
    unsigned int k = 4294967295;    // 4 bytes (0 - +4,294,967,295)               %u

    long long int l = 9223372036854775807;              // 8 bytes (-9 quintillion - +9 quintillion)  %lld
    unsigned long long int m = 18446744073709551615u;    // 8 bytes (0 - +18 quintillion)              %llu

    printf("%c\n", a);
    printf("%s\n", b);

    printf("%f\n", c);
    printf("%lf\n", d);

    printf("%d\n", e);

    printf("%d\n", f); // %d
    printf("%c\n", f); // %c
    printf("%d\n", g); // %d
    printf("%c\n", g); // %c

    printf("%d\n", h);
    printf("%d\n", i);

    printf("%d\n", j);
    printf("%u\n", k);

    printf("%lld\n", l);
    printf("%llu\n", m);

    return 0;
}