#include <iostream>

int main() {
    class point {
        public:                         // public = can be accessed by anyone
            double getx() {
                return x;               // inline
            }
            void setx(double v) {
                x = v;                  // mutator
            }

        private:                        // private = only to this scope
            double x, y;                // hide representation
    };
}