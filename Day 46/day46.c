/*
Q91: Remove all vowels from a string.

Sample Test Cases:
Input 1:
education
Output 1:
dctn

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            continue;
        }
        putchar(str[i]);
    }

    return 0;
}
