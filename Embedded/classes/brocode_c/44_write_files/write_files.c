#include <stdio.h>

int main() {
    // w = write to file (will overwrite)
    // a = appends to file
    // r = reads a file

    FILE *pF = fopen("write-files.txt", "w");  
    // FILE *pF = fopen("C:\\Users\\kinpu\\OneDrive\\Desktop\\write-files.txt", "w");   // you can also preceed "write-files.txt" with a path to write to that path

    fprintf(pF, "Hello!!!!!");

    fclose(pF);

    /*
    if(remove("write-files.txt") == 0) {
        printf("File deleted successfully!");
    } else {
        printf("Error deleting file");
    }
    */

    return 0;
}