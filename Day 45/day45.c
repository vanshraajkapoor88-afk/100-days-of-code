/*
Q89: Count frequency of a given character in a string.

Sample Test Cases:
Input 1:
programming
g
Output 1:
2

*/

#include <stdio.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int len = 0;
    while (str[len] != '\0' && str[len] != '\n' && str[len] != '\r') {
        len++;
    }
    str[len] = '\0';

    char targetLine[100];
    if (!fgets(targetLine, sizeof(targetLine), stdin)) return 0;
    char target = targetLine[0];

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
