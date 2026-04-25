#include <iostream>
#include <tuple>

using std::cout;
using std::endl;
using std::tuple;
using std::make_tuple;
using std::ostream;
using std::get;

class threeD {
    public:
        threeD() {
            make_tuple(0, 0, 0);
        }
        threeD(double x, double y, double z) {
            p = make_tuple(x, y, z);
        }
        friend ostream& operator << (ostream& out, threeD& d) {
            out << "(" << get<0>(d.p) << "," << get<1>(d.p) << "," << get<2>(d.p) << ")";
            return out;
        }
    private:
        tuple<double, double, double> p;
};

// explain make_tuple() and get<i>()
int main() {
    threeD p1, p2(1.2, 2.3, 3.4);
    cout << "Test tuple" << endl;
    cout << "p1 is " << p1 << endl;
    cout << "p1 is " << p2 << endl;
    return 0;
}