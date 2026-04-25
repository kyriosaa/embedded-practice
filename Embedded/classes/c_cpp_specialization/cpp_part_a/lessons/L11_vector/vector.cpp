#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
    int howMany;
    cout << "How many ints in data?: " << endl;
    cin >> howMany;
    vector<int> data (howMany);
    cout << "The contents of data: ";
    for(vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
        cin >> *it;
    }
    // more code
}