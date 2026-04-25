// Here we use a vector and its associated iterator.
// Think of p as conceptually a pointer. It has two endpoints that define its range:
//      v.begin()
//      v.end()
//  Where v.begin() stores a value, but v.end() does not.

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int>v(100);  // allocating space

    for(int i = 0; i < 100; ++i) {
        v[i] = i;
    }
    for(vector<int>::iterator p = v.begin(); p != v.end(); ++p) {
        cout << *p << '\t';
    }
    cout << endl;
}