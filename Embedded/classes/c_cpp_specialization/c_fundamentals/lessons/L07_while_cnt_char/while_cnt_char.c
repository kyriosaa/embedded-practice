#include <stdio.h>

int main() {
    int blanks = 0;
    int digits = 0;
    int letters = 0;
    int others = 0;
    int c;

    while((c = getchar()) != EOF) {     // EOF = End Of File

        if(c == ' ') {
            ++blanks;
        } else if(c >= '0' && c <= '9') {
            ++digits;
        } else if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            ++letters;
        } else {
            ++others;
        }
    }

    printf("blanks = %d, digits = %d, letters = %d, others = %d\n", blanks, digits, letters, others);

    return 0;
}