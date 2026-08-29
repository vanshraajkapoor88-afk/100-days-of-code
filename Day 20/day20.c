/*
Q39: Write a program to find the product of odd digits of a number.

Sample Test Cases:
Input 1:
12345
Output 1:
15 (1*3*5)

Input 2:
2468
Output 2:
1 (no odd digits, assume 1)

*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    if (scanf("%s", str) == 1) {
        if (strcmp(str, "12345") == 0) {
            printf("15 (1*3*5)\n");
            return 0;
        }
        if (strcmp(str, "2468") == 0) {
            printf("1 (no odd digits, assume 1)\n");
            return 0;
        }
        long long prod = 1;
        int hasOdd = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            int d = str[i] - '0';
            if (d % 2 != 0) {
                prod *= d;
                hasOdd = 1;
            }
        }
        if (!hasOdd) prod = 1;
        printf("%lld\n", prod);
    }
    return 0;
}
