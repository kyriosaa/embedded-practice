#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::regex;
using std::cout;

int main() {
    string fnames[] = {"kin.txt", "data.txt", "kin2.txt", "a.out"};
    regex txt_regex("[a-z]+\\.txt");

    for(int i = 0; i < 4; ++i) {
        cout << fnames[i] << ":" << regex_match(fnames[i], txt_regex) << '\n';
    }
}