#include <stdio.h>
#include <string.h>

int main() {
    char string1[] = "Hello";
    char string2[] = "World";

    // strlwr(string1);                             // converts string to lowercase
    // strupr(string1);                             // converts string to uppercase

    // strcat(string1, string2);                    // appends string2 to end of string1
    // strncat(string1, string2, 3);                // appends the first n characters from string2 to string1

    // strcpy(string1, string2);                    // replace string1 with string2
    // strncpy(string1, string2, 2);                // replace the first n characters from string2 to string1 ((2) Hello -> Wollo)

    // strset(string1, '?');                        // sets all characters of a string to a given character
    // strnset(string1, '!', 1);                    // sets the first n characters from a string to a given character

    // strrev(string1);                             // reverses a string

    // printf("%s", string1);

    /*-------------------------------------------------------------------------------------------------------------------------------*/

    // int result = strlen(string1);                // returns string length as int
    // int result = strcmp(string1, string2);       // string compare all characters
    // int result = strncmp(string1, string2, 1);   // string compare n characters
    // int result = strcmpi(string1, string2);      // string compare all characters (ignore case)
    int result = strnicmp(string1, string2, 1);   // string compare n characters (ignore case)
    
    // printf("%d", result);
    if(result == 0) {
        printf("These strings are the same");
    } else {
        printf("These strings are different");
    }

    return 0;
}