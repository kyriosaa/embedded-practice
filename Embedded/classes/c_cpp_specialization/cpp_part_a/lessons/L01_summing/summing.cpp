#include <iostream>

double sum(double *data, int size) {
    double sum = 0.0;
    for(int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

int main() {
    double data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data)/sizeof(data[0]);

    double total = sum(data, size);

    std::cout << total << std::endl;

    return 0;
}