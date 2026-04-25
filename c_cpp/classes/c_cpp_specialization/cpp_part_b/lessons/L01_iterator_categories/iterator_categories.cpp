#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;

template <typename ForwardIterator>

void square(ForwardIterator first, ForwardIterator last) {
    for(; first != last; first++) {
        *first = (*first) * (*first);
    }
}

int main() {
    // ...
    square(w.begin(), w.end());
    for(auto i:w) {     // range for the following
        cout << i << "\t";
    }
    cout << endl;
}