/*
Q98: Print initials of a name with the surname displayed in full.

Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    char words[20][100];
    int wordCount = 0;

    int i = 0;
    while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r') {
        while (str[i] == ' ' || str[i] == '\t') i++;
        if (str[i] == '\0' || str[i] == '\n' || str[i] == '\r') break;

        int len = 0;
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            words[wordCount][len++] = str[i++];
        }
        words[wordCount][len] = '\0';
        wordCount++;
    }

    if (wordCount == 0) return 0;

    if (wordCount == 1) {
        printf("%s\n", words[0]);
    } else {
        for (int w = 0; w < wordCount - 1; w++) {
            printf("%c.", toupper((unsigned char)words[w][0]));
        }
        printf(" %s\n", words[wordCount - 1]);
    }

    return 0;
}
