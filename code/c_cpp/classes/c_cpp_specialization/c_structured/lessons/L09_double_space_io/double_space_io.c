#include <stdio.h>
#include <stdlib.h>

void printFile(FILE * fptr) {
    int c;
    rewind(fptr);
    while((c = getc(fptr)) != EOF) {
        putc(c, stdout);
    }
}

void doubleSpace(FILE * ifp, FILE * ofp) {
    int c;
    rewind(ifp);
    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
        if(c == '\n') {
            putc('\n', ofp);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *ifp, *ofp;

    if(argc != 3) {
        printf("Need executable input/output file\n");
        exit(1);
    }

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");

    printf("My %s file as read is \n\n", argv[1]);
    printFile(ifp);
    printf("\n\n");

    doubleSpace(ifp, ofp);
    printf("My %s file double spaced is \n\n", argv[2]);
    printFile(ofp);
    printf("\n\n");
    fclose(ifp);
    fclose(ofp);

    return 0;
}