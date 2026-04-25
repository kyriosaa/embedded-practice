#include <iostream>

using std::cout;
using std::endl;

// ------------------------------------------------------------------------
// previous lesson code so it works properly
struct list_element {
    list_element(int n = 0, list_element* ptr = 0): d(n), next(ptr){}
    int d;
    list_element* next;
};

class list {
    public:
        list(): head(0), cursor(0) {}
        
        void prepend(int n);    // insert at front value n

        int get_element() {
            return cursor->d;
        }

        void advance() {
            cursor = cursor->next;
        }

        void print();

    private:
        list_element* head;
        list_element* cursor;
};

void list::prepend(int n) {
    if(head == 0)   // empty list case
        cursor = head = new list_element(n, head);
    else            // add to front chain
        head = new list_element(n, head);
}
// ------------------------------------------------------------------------

void list::print() {
    list_element* h = head;
    
    while(h != 0) {
        cout << h->d << ", ";
        h = h->next;
    }
    cout << "###" << endl;
}

int main() {
    list a;
    list b;

    a.prepend(9);
    a.prepend(8);

    cout << " list a" << endl;

    a.print();

    for(int i = 0; i < 40; ++i) {
        b.prepend(i*i);
    }

    cout << " list b" << endl;

    b.print();
}