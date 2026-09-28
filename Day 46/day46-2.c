/*
Q92: Find the first repeating lowercase alphabet in a string.

Sample Test Cases:
Input 1:
stress
Output 1:
s

*/

#include <stdio.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int freq[26] = {0};
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n' && str[len] != '\r') {
        if (str[len] >= 'a' && str[len] <= 'z') {
            freq[str[len] - 'a']++;
        }
        len++;
    }

    char firstRepeating = '\0';
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && freq[str[i] - 'a'] > 1) {
            firstRepeating = str[i];
            break;
        }
    }

    if (firstRepeating != '\0') {
        printf("%c\n", firstRepeating);
    } else {
        printf("None\n");
    }

    return 0;
}
