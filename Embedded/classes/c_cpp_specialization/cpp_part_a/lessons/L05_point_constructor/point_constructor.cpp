#include <iostream>

class point {
    public:
        point(double x = 0.0, double y = 0.0) : x(x), y(y){}    // constructor

        double getx() {
            return x;
        }

        void setx(double v) {
            x = v;
        }
    

    private:
        double x, y;
};

// note: class_name(): initializer list syntax