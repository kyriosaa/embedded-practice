// "A Book on C" - Chapter 2 Q23
// Measure the time it takes to call rand()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCALLS 10000000     // number of fct calls
#define NCOLS 8             // number of columns
#define NLINES 3            // number of lines

int main() {
    int i;
    int val;
    long begin;
    long diff;
    long end;

    begin = time(0);        // record the beginning time for later comparison
    srand(time(0));         // generate random seed
    printf("\nTIMING TEST: %d calls to rand()\n", NCALLS);

    for(i = 1; i <= NCALLS; ++i) {
        val = rand();

        if(i <= NCOLS * NLINES) {
            printf("%7d", val);

            if(i % NCOLS == 0) {
                putchar('\n');
            } 
        } else if(i == NCOLS * NLINES + 1) {
            printf("%7s\n", ".....");
        }
    }

    end = time(NULL);
    diff = end - begin;
    
    printf("%s%ld\n%s%ld\n%s%ld\n%s%.10f\n",
        "       end time: ", end,
        "     begin time: ", begin,
        "   elapsed time: ", diff,
        "time for each call: ", (double) diff / NCALLS);

    return 0;
}

// once again the syntax they write in the book is so weird and I just dont really understand it