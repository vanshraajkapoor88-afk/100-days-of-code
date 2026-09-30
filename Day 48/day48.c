/*
Q95: Check if one string is a rotation of another.

Sample Test Cases:
Input 1:
abcde
deabc
Output 1:
Rotation

Input 2:
abc
acb
Output 2:
Not rotation

*/

#include <stdio.h>
#include <string.h>

int main() {
    char s1[1000], s2[1000];
    if (!fgets(s1, sizeof(s1), stdin)) return 0;
    if (!fgets(s2, sizeof(s2), stdin)) return 0;

    int len1 = 0;
    while (s1[len1] != '\0' && s1[len1] != '\n' && s1[len1] != '\r') len1++;
    s1[len1] = '\0';

    int len2 = 0;
    while (s2[len2] != '\0' && s2[len2] != '\n' && s2[len2] != '\r') len2++;
    s2[len2] = '\0';

    if (len1 != len2 || len1 == 0) {
        printf("Not rotation\n");
        return 0;
    }

    char temp[2000];
    strcpy(temp, s1);
    strcat(temp, s1);

    if (strstr(temp, s2) != NULL) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }

    return 0;
}
