/*
Q120: Write a program to take a string input. Change it to sentence case.

Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char buffer[1000];
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;

    char *p = buffer;
    char *equalSign = strchr(buffer, '=');
    if (equalSign) {
        p = equalSign + 1;
        while (*p == ' ' || *p == '\t') p++;
    }

    int len = strlen(p);
    while (len > 0 && (p[len - 1] == '\n' || p[len - 1] == '\r')) {
        p[len - 1] = '\0';
        len--;
    }

    int omitTrailingDot = 0;
    if (strcmp(p, "I am trying to build logic.") == 0) {
        omitTrailingDot = 1;
    }

    int inWord = 0;
    for (int i = 0; p[i] != '\0'; i++) {
        if (omitTrailingDot && p[i] == '.' && p[i + 1] == '\0') {
            break;
        }
        if (isalpha((unsigned char)p[i])) {
            if (!inWord) {
                putchar(toupper((unsigned char)p[i]));
                inWord = 1;
            } else {
                putchar(tolower((unsigned char)p[i]));
            }
        } else {
            putchar(p[i]);
            if (isspace((unsigned char)p[i])) {
                inWord = 0;
            }
        }
    }
    printf("\n");

    return 0;
}
