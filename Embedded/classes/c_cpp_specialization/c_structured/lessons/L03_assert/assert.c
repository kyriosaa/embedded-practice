#define NDEBUG      // goes before <assert.h>
#include <assert.h>
#include <stdio.h>

int main() {
    double x;
    double y;

    while(1) {
        printf("Read in 2 floats: \n");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("when dividing x by y = %lf\n", x/y);
    }

    return 0;
}