/*
Q93: Check if two strings are anagrams of each other.

Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[1000], s2[1000];
    if (!fgets(s1, sizeof(s1), stdin)) return 0;
    if (!fgets(s2, sizeof(s2), stdin)) return 0;

    int count1[26] = {0}, count2[26] = {0};
    int len1 = 0, len2 = 0;

    for (int i = 0; s1[i] != '\0' && s1[i] != '\n' && s1[i] != '\r'; i++) {
        if (isalpha((unsigned char)s1[i])) {
            count1[tolower((unsigned char)s1[i]) - 'a']++;
            len1++;
        }
    }
    for (int i = 0; s2[i] != '\0' && s2[i] != '\n' && s2[i] != '\r'; i++) {
        if (isalpha((unsigned char)s2[i])) {
            count2[tolower((unsigned char)s2[i]) - 'a']++;
            len2++;
        }
    }

    int anagram = 1;
    if (len1 != len2) {
        anagram = 0;
    } else {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                anagram = 0;
                break;
            }
        }
    }

    if (anagram) {
        printf("Anagrams\n");
    } else {
        printf("Not anagrams\n");
    }

    return 0;
}
