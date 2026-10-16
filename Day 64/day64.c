/*
Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3

*/

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1000];
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;

    char str[1000];
    char *quote1 = strchr(buffer, '"');
    if (quote1) {
        char *quote2 = strchr(quote1 + 1, '"');
        if (quote2) {
            int len = quote2 - (quote1 + 1);
            strncpy(str, quote1 + 1, len);
            str[len] = '\0';
        } else {
            strcpy(str, quote1 + 1);
        }
    } else {
        strcpy(str, buffer);
        int len = strlen(str);
        while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
            str[len - 1] = '\0';
            len--;
        }
    }

    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (lastIndex[c] >= start) {
            start = lastIndex[c] + 1;
        }
        lastIndex[c] = i;
        int currentLen = i - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}
