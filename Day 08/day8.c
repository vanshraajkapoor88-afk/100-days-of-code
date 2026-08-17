/*
Q15: Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.

Sample Test Cases:
Input 1:
A
Output 1:
Uppercase alphabet

Input 2:
a
Output 2:
Lowercase alphabet

Input 3:
3
Output 3:
Digit

Input 4:
#
Output 4:
Special character

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    if (scanf(" %c", &ch) == 1) {
        if (isupper((unsigned char)ch)) {
            printf("Uppercase alphabet\n");
        } else if (islower((unsigned char)ch)) {
            printf("Lowercase alphabet\n");
        } else if (isdigit((unsigned char)ch)) {
            printf("Digit\n");
        } else {
            printf("Special character\n");
        }
    }
    return 0;
}
