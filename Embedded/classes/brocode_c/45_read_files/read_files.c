#include <stdio.h>

int main() {
    FILE *pF = fopen("read-files.txt", "r");
    // FILE *pF = fopen("C:\\Users\\kinpu\\OneDrive\\Desktop\\read-files.txt", "r");   // you can also preceed "read-files.txt" with a path to read to that path
    char buffer[255];

    if(pF == NULL) {
        printf("Unable to open file\n");
    } else {
        while(fgets(buffer, 255, pF) != NULL) {
            printf("%s", buffer);
        }
    }

    fclose(pF);

    return 0;
}