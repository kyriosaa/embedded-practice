#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::thread;

void message1() {
    cout << "Write a message\n";
}

int main(int argc, char ** argv) {
    thread foo([]() {
        // declare as a thread a lambda expression
        cout << "Hello World\n";
    });
    thread thr1(message1);
    thr1.join();
    foo.join();
}