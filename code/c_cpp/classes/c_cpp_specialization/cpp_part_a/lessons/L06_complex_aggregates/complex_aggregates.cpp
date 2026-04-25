#include <iostream>

struct list_element {
    list_element(int n = 0, list_element* ptr = 0): d(n), next(ptr){}
    int d;
    list_element* next;
};