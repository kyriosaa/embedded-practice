#include <stdio.h>
#include <string.h>

struct Student {
    char name[12];
    float gpa;
};

int main() {
    struct Student student1 = {"Spongebob", 3.2};
    struct Student student2 = {"Patrick", 1.2};
    struct Student student3 = {"Sandy", 4.0};
    struct Student student4 = {"Squidward", 2.9};

    struct Student students[] = {student1, student2, student3, student4};
    int arrayLength = sizeof(students) / sizeof(students[0]);

    for(int i = 0; i < arrayLength; i++) {
        printf("%-12s\t", students[i].name);
        printf("%.1f\n", students[i].gpa);
    }

    return 0;
}