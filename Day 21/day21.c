/*
Q41: Write a program to swap the first and last digit of a number.

Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001

*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    if (scanf("%s", str) == 1) {
        int len = strlen(str);
        if (len > 1) {
            char temp = str[0];
            str[0] = str[len - 1];
            str[len - 1] = temp;
        }
        printf("%s\n", str);
    }
    return 0;
}
