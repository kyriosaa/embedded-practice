#include <iostream>
#include <cmath>

class point:public duo {
    public:
        point():duo() {}    // init base object
        point(double x, double y = 0.0):duo(x, y) {}
        virtual double length() {
            return sqrt(first* first + second* second);
        }
};  // virtual is pure polymorphism and remains

class point3d:public point {
    public:
        point3d():point(), z(0.0) {}
        double length() {
            return sqrt(first* first + second* second + z* z);  // virtual
        }
        void setZ(double d) {
            z = d;
        }
    public:
        double z;
}