#include <stdio.h>
#include <stdlib.h>

void output(int n, int data[], double average, int max, FILE *ofp) {
    // printing to console
    printf("Number of elements: %d\n", n);
    printf("Values: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\nAverage: %f\n", average);
    printf("Max: %d\n", max);

    // output to file
    fprintf(ofp, "Number of elements: %d\n", n);
    fprintf(ofp, "Values: ");
    for(int i = 0; i < n; i++) {
        fprintf(ofp, "%d ", data[i]);
    }
    fprintf(ofp, "\nAverage: %f\n", average);
    fprintf(ofp, "Max: %d\n", max);
}

void compute(FILE *ifp, FILE *ofp) {
    int n;

    // count check
    rewind(ifp);
    if(fscanf(ifp, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Missing count\n");
        return;
    }

    // memory allocation check
    int *data = malloc(n * sizeof(int));
    if(data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int max = -2147483648;  // smallest 32-bit signed int
    double sum = 0;

    for(int i = 0; i < n; i++) {
        if(fscanf(ifp, "%d", &data[i]) != 1) {
            fprintf(stderr, "Not enough integers in file\n");
            free(data);
            return;
        }
        sum += data[i];     // add sum
        if(data[i] > max) {
            max = data[i];  // find max
        }
    }

    double average = sum / n;

    output(n, data, average, max, ofp);

    free(data);
}

int main(int argc, char *argv[]) {
    FILE *ifp, *ofp;

    if(argc != 3) {
        printf("Usage: %s inputFile outputFile\n", argv[0]);
        exit(1);
    }

    ifp = fopen(argv[1], "r");
    ofp = fopen(argv[2], "w");

    // file check
    if(ifp == NULL || ofp == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    compute(ifp, ofp);

    // close files after use
    fclose(ifp);
    fclose(ofp);

    return 0;
}