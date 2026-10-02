/*
Q100: Print all sub-strings of a string.

Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c

*/

#include <stdio.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int len = 0;
    while (str[len] != '\0' && str[len] != '\n' && str[len] != '\r') len++;
    str[len] = '\0';

    int first = 1;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (!first) {
                printf(",");
            }
            first = 0;
            for (int k = i; k <= j; k++) {
                putchar(str[k]);
            }
        }
    }
    printf("\n");

    return 0;
}
