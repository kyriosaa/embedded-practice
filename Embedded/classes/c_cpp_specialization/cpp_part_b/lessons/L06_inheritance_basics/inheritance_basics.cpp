#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class duo {
    public:
        duo():first(0.0), second(0.0) {}
        void setFirst(double d) {
            first = d;
        }
        void setSecond(double d) {
            second = d;
        }
        double getFirst() {
            return first;
        }
        double getSecond() {
            return second;
        }
    protected:      // intermediate data hiding -nb needed for this example
        double first;
        double second;
};

class point:public duo {
    public:
        double length() {
            return sqrt(first* first + second* second);
        }
};

int main() {
    point q;
    q.setFirst(3.0);
    q.setSecond(4.0);
    
    cout << q.getFirst() << ", " << q.getSecond() << endl;
    cout << q.length() << endl;

    return 0;
}