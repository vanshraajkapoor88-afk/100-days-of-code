/*
Q94: Find the longest word in a sentence.

Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    char longestWord[1000] = "";
    int maxLen = 0;

    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') i++;
        if (str[i] == '\0') break;

        char currentWord[1000];
        int wLen = 0;
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            currentWord[wLen++] = str[i++];
        }
        currentWord[wLen] = '\0';

        if (wLen > maxLen) {
            maxLen = wLen;
            strcpy(longestWord, currentWord);
        }
    }

    printf("%s\n", longestWord);
    return 0;
}
