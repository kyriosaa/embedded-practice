#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

enum class suit: short {SPADE, HEART, DIAMOND, CLUB};

class pips {
    public:
        pips(int val):v(val){assert(v > 0 && v < 14);}
        friend ostream& operator << (ostream& out, const pips& p);
        int getPips() {
            return v;
        }
    private:
        int v;
};

ostream& operator << (ostream& out, const pips& p) {
    static const char* names[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    out << names[p.v-1];
    return out;
}

ostream& operator << (ostream& out, const suit& s) {
    static const char* suits[] = {"♠", "♥", "♦", "♣"};
    out << suits[static_cast<int>(s)];
    return out;
}

class card {
    public:
        card():s(suit::SPADE), v(1){}
        card(suit s, pips v):s(s), v(v){}
        friend ostream& operator << (ostream& out, const card& c);
        suit getSuit() {
            return s;
        }
        pips getPips() {
            return v;
        }
    private:
        suit s;
        pips v;
};

ostream& operator << (ostream& out, const card& c) {
    cout << c.v << c.s;     // presumes << overloaded for pips and suit
    return out;
}

void initDeck(vector<card> & d) {
    for(int i = 1; i < 14; ++i) {
        card c(suit::SPADE, i);
        d[i-1] = c;
    }
    for(int i = 1; i < 14; ++i) {
        card c(suit::HEART, i);
        d[i+12] = c;
    }
    for(int i = 1; i < 14; ++i) {
        card c(suit::DIAMOND, i);
        d[i+25] = c;
    }
    for(int i = 1; i < 14; ++i) {
        card c(suit::CLUB, i);
        d[i+38] = c;
    }
};

void print(vector<card> & deck) {
    for(auto cardval:deck) {
        cout << cardval;
    }
    cout << endl;
}

bool isFlush(vector<card> & hand) {
    suit s = hand[0].getSuit();
    for(auto p = hand.begin() + 1; p != hand.end(); ++p) {
        if(s != p -> getSuit()) {
            return false;
        }
    }
    return true;
}

bool isStraight(vector<card> & hand) {
    int pipsV[5];
    int i = 0;

    for(auto p = hand.begin(); p != hand.end(); ++p) {
        pipsV[i++] = (p -> getPips()).getPips();
    }
    sort(pipsV, pipsV + 5); // stl iterator range
    if(pipsV[0] != 1) {     // non-aces
        return  
            (pipsV[0] == pipsV[1]-1 && pipsV[1] == pipsV[2]-1) &&
            (pipsV[2] == pipsV[3]-1 && pipsV[3] == pipsV[4]-1);
    } else {                // aces
        return 
            ((pipsV[0] == pipsV[1]-1 && pipsV[1] == pipsV[2]-1) &&
            (pipsV[2] == pipsV[3]-1 && pipsV[3] == pipsV[4]-1)) ||
            ((pipsV[1] == 10) && (pipsV[2] == 11) && (pipsV[3] == 12) && (pipsV[4] == 13));
    }
}

bool isStraightFlush(vector<card> & hand) {
    return isFlush(hand) && isStraight(hand);
}

int main() {
    vector<card> deck(52);
    srand(time(0));
    initDeck(deck);

    int howMany;
    int flushCount = 0;
    int strCount = 0;
    int strFlushCount = 0;

    cout << "How many shuffles?";
    cin >> howMany;

    for (int j = 0; j < howMany; j++) {
        std::shuffle(deck.begin(), deck.end(), std::mt19937{std::random_device{}()});    // STL algorithm
        vector<card> hand(5);
        int i = 0;

        for(auto p = deck.begin(); i < 5; ++p) {
            hand[i++] = *p;
        }

        if(isFlush(hand)) {
            flushCount++;
        }
        if(isStraight(hand)) {
            strCount++;
        }
        if(isStraightFlush(hand)) {
            strFlushCount++;
        }
    }

    cout << "Flushes " << flushCount << " out of " << howMany << endl;
    cout << "Straights " << strCount << " out of " << howMany << endl;
    cout << "Straight Flushes " << strFlushCount << " out of " << howMany << endl;

    return 0;
}