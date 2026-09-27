/*
Q90: Toggle case of each character in a string.

Sample Test Cases:
Input 1:
Hello
Output 1:
hELLO

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (islower((unsigned char)str[i])) {
            str[i] = toupper((unsigned char)str[i]);
        } else if (isupper((unsigned char)str[i])) {
            str[i] = tolower((unsigned char)str[i]);
        }
    }

    printf("%s", str);
    return 0;
}
