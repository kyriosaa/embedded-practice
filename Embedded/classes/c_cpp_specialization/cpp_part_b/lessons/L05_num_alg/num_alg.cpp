#include <iostream>
#include <algorithm>
#include <numeric>

using std::accumulate;
using std::inner_product;
using std::cout;
using std::endl;

int main() {
    double v1[3] = {1.0, 2.5, 4.6};
    double v2[3] = {1.0, 2.0, -3.5};
    double sum;
    double inner_p;

    sum = accumulate(v1, v1+3, 0.0);
    inner_p = inner_product(v1, v1+3, v2, 0.0);

    cout << "sum = " << sum << ", product = " << inner_p << endl;
}