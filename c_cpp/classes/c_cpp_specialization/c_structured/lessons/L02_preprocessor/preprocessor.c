#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEPHANT_SEAL_WT_MALE 8800
#define MIN_ELEPHANT_SEAL_WT_MALE 4400

// produce macro that randomly generates a male weight
#define RANGE           4400
#define POPULATION      1000
#define WEIGHT_OVER     rand() % RANGE
#define WEIGHT          WEIGHT_OVER + MIN_ELEPHANT_SEAL_WT_MALE
#define FILL            for(int i = 0; i < POPULATION; i++) data[i] = WEIGHT

// ----- func declarations -----
void printData(int d[], int size);
// -----------------------------

int main() {
    int data[POPULATION];
    srand(time(0));
    FILL;
    printData(data, POPULATION);
    printf("\n\n");
    return 0;
}

void printData(int data[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\t", data[i]);
        if((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}