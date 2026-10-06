/*
Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main() {
    char buffer[256];
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;

    char *p = buffer;
    while (*p && !isdigit(*p) && *p != '-') p++;
    if (!*p) return 0;
    long long n = strtoll(p, NULL, 10);

    long long total = n * (n + 1) / 2;
    long long x = (long long)round(sqrt(total));

    if (x * x == total) {
        printf("%lld\n", x);
    } else {
        printf("-1\n");
    }

    return 0;
}
