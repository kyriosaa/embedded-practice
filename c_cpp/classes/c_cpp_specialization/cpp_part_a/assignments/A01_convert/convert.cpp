// Convert this program to C++
//
// Change to C++ io
// Change to one line comments (this)
// Change defines of constants to const
// change array to vector<>
// inline any short function

#include <iostream>
#include <vector>

const int N = 40;   // use const int instead of #define

void sum(int &p, int n, const std::vector<int>&d) {     // use vector instead of array[]
    p = 0;

    for(int i = 0; i < n; ++i) {
        p += d[i];
    }
}

int main() {
    int accum = 0;
    std::vector<int> data(N);

    for(int i = 0; i < N; ++i) {
        data[i] = i;
    }

    sum(accum, N, data);

    std::cout << "sum is " << accum << "\n";    // use std::cout instead of printf

    return 0;
}