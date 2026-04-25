#include <iostream>
using std::cout;    // can reduce typing

namespace none {
    int x = 0;
}

namespace first {
    int x = 1;
}

namespace second {
    int x = 2;
}

int main() {
    // Namespace = provides a solution for preventing name conflicts
    //             in large projects. Each identity needs a unique name.
    //             A namespace allows for identically named entities
    //             as long as the namespaces are different.

    using namespace first;

    cout << none::x;
    cout << x;
    cout << second::x;

    return 0;
}