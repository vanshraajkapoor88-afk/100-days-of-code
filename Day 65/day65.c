/*
Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void extractString(const char *src, const char *key, char *dest) {
    dest[0] = '\0';
    char *pos = strstr(src, key);
    if (pos) {
        char *q1 = strchr(pos, '"');
        if (q1) {
            char *q2 = strchr(q1 + 1, '"');
            if (q2) {
                int len = q2 - (q1 + 1);
                strncpy(dest, q1 + 1, len);
                dest[len] = '\0';
                return;
            }
        }
    }
}

int main() {
    char buffer[2000];
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;

    char s[1000] = "", t[1000] = "";
    extractString(buffer, "s =", s);
    extractString(buffer, "t =", t);

    if (strlen(s) == 0 && strlen(t) == 0) {
        sscanf(buffer, "%s %s", s, t);
    }

    int count[26] = {0};
    int len_s = strlen(s), len_t = strlen(t);

    if (len_s != len_t) {
        printf("Not Anagram\n");
        return 0;
    }

    for (int i = 0; i < len_s; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    int isAnagram = 1;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram) {
        printf("Anagram\n");
    } else {
        printf("Not Anagram\n");
    }

    return 0;
}
