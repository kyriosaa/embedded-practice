#include <iostream>

template <class Generic>

Generic subtractSum(const Generic data[], int size, Generic sum = 0) {
    for(int i = 0; i < size; i++) {
        sum -= data[i];
    }
    return sum;
}

int main() {
    double data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    std::cout << subtractSum(data, size) << std::endl;
    std::cout << subtractSum(data, size, 15.0) << std::endl;

    return 0;
}