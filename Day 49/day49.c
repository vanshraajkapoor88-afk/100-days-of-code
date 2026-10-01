/*
Q97: Print the initials of a name.

Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int inWord = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n' && str[i] != '\r'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            if (!inWord) {
                printf("%c.", toupper((unsigned char)str[i]));
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    printf("\n");
    return 0;
}
