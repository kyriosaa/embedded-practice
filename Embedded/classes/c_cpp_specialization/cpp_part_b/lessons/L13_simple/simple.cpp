#include <iostream>
#include <string>

class simple {
    public:
        simple() = default;  // compiler generated
        simple(double x) = delete;   // supressed conversion constructor

        simple(int x, int y): p(x), q(y) {}
        simple(int x): simple(x, 1) {}  // delegate constructor
        simple(const simple& x): simple(x.p, x.q) {}    // delegate constructor
        simple(simple&& x): simple(x.p, x.q) {
            x.p = x.q = 0;  // move semantics
        }
    private:
        int p = 0;
        int q = 1;
        // these can be overridden
};

class rational: public simple {
    public:
        using simple::simple;   // implicitly declares constructors
                                // but uses base
};