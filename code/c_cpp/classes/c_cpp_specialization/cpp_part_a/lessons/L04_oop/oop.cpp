#include <iostream>

using std::cout;
using std::endl;

int main() {

    {
        int i = 9;
        int j = 3;

        cout << "i is " << i << "; j is " << j << endl;

        {
            int i = j + 2;

            cout << "i is " << i << "; j is " << j << endl;
        }

        cout << "i is " << i << "; j is " << j << endl;
    }

    return 0;
}