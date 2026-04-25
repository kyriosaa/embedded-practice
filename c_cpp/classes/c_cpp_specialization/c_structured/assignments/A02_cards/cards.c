#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef enum suit {clubs, diamonds, hearts, spades} Suit;
typedef struct card {Suit suit; short pips;} Card;

// --- func declarations ---
void initDeck(Card deck[]);
void swapCards(Card *a, Card *b);
void shuffleDeck(Card deck[], int deckSize);
void analyze(Card hand[], int handSize, int *noPair, int *onePair, int *twoPair, int *threeOfAKind, int *fullHouse, int *fourOfAKind);
// -------------------------

int main() {
    // random num generator
    srand((int)time(NULL));

    // 52 cards in a normal deck
    Card deck[52];
    initDeck(deck);

    // let user decide how many simulations they want to have (above 1 million)
    int simulationsCount;
    do {
        printf("Enter amount of simulations (over 1000000): ");
        scanf("%d", &simulationsCount);

        if(simulationsCount < 1000000) {
            printf("The number you entered is not over 1000000. Please enter a valid number.\n\n");
        }
    } while(simulationsCount < 1000000);
    

    // hand size is always 7
    #define HAND_SIZE 7

    int noPair       = 0;
    int onePair      = 0;
    int twoPair      = 0;
    int threeOfAKind = 0;
    int fullHouse    = 0;
    int fourOfAKind  = 0;

    printf("%d simulations with a hand size of %d.", simulationsCount, HAND_SIZE);

    for(int i = 0; i < simulationsCount; i++) {
        shuffleDeck(deck, 52);

        // deal hand
        Card hand[HAND_SIZE];
        for(int i = 0; i < HAND_SIZE; i++) {
            hand[i] = deck[i];
        }

        analyze(hand, HAND_SIZE, &noPair, &onePair, &twoPair, &threeOfAKind, &fullHouse, &fourOfAKind);
    }

    int total = noPair + onePair + twoPair + threeOfAKind + fullHouse + fourOfAKind;

    printf("\n---------- Results ----------\n");
    printf("(%d simulations with %d card hands)\n\n", simulationsCount, HAND_SIZE);
    printf("Hand Type       | Count       |Probability\n\n");
    printf("Four Of A Kind  | %-11d |%.6f\n", fourOfAKind, (double)fourOfAKind / simulationsCount);
    printf("Full House      | %-11d |%.6f\n", fullHouse, (double)fullHouse / simulationsCount);
    printf("Three Of A Kind | %-11d |%.6f\n", threeOfAKind, (double)threeOfAKind / simulationsCount);
    printf("Two Pair        | %-11d |%.6f\n", twoPair, (double)twoPair / simulationsCount);
    printf("One Pair        | %-11d |%.6f\n", onePair, (double)onePair / simulationsCount);
    printf("No Pair         | %-11d |%.6f\n", noPair, (double)noPair / simulationsCount);
    printf("\n");
    printf("Total           | %-11d |%.6f\n", total, (double)total / simulationsCount);

    return 0;
}

void initDeck(Card deck[]) {
    int index = 0;

    for(int i = clubs; i <= spades; i++) {     // for loop from clubs to spades
        for(int j = 1; j <= 13; j++) {
            deck[index].suit = (Suit)i;
            deck[index].pips = j;
            index++;
        }
    }
}

void swapCards(Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleDeck(Card deck[], int deckSize) {
    for(int i = deckSize; i > 0; i--) {
        int j = rand() % (i + 1);           // generate random num between 0 and i
        swapCards(&deck[i], &deck[j]);      // swap current card with card at the randomly generated num
    }
}

void analyze(Card hand[], int handSize, int *noPair, int *onePair, int *twoPair, int *threeOfAKind, int *fullHouse, int *fourOfAKind) {
    // count how many times each pip value appears
    int pipsCounts[14] = {0};
    for(int i = 0; i < handSize; i++) {
        pipsCounts[hand[i].pips]++;
    }

    // count the pairs, threes, and fours
    int pairs   = 0;
    int threes  = 0;
    int fours   = 0;
    for(int i = 1; i <= 13; i++) {
        switch(pipsCounts[i]) {
            case 2:
                pairs++;
                break;
            case 3:
                threes++;
                break;
            case 4:
                fours++;
                break;
        }
    }

    // increment counter respective to hand type
    if(fours == 1) {
        (*fourOfAKind)++;
    } else if(threes == 1 && pairs == 1) {
        (*fullHouse)++;
    } else if(threes == 1) {
        (*threeOfAKind)++;
    } else if(pairs == 2) {
        (*twoPair)++;
    } else if(pairs == 1) {
        (*onePair)++;
    } else {
        (*noPair)++;
    }
}