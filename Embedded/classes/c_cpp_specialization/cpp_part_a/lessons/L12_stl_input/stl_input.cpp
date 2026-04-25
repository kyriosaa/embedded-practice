#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream wordFile("word.txt");
    istream iterator<string> start(wordFile), end;
    vector<string> words(start, end);

    cout << "\n\nwords as read\n";
    for(auto str: words) {
        cout << str << "\t";
    }
    sort(words.begin(), words.end());
    cout << "\n\nwords are sorted\n";
    for(auto str: words) {
        cout << str << "\t";
    }
    cout << endl;
}