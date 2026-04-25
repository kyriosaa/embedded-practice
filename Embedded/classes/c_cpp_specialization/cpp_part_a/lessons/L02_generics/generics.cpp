#include <iostream>

template <class Generic>

Generic sum(const Generic data[], int size, Generic sum = 0) {
    for(int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

int main() {
    double data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    std::cout << sum(data, size) << std::endl;          // by default, sum = 0
    std::cout << sum(data, size, 58.0) << std::endl;    // we can pass in another parameter to make sum = 58

    return 0;
}