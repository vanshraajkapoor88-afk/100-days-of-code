/*
Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.

Sample Test Cases:
Input 1:
nums1 = [2,7,11,15] nums2 = [4,8,10]
Output 1:
2 4 7 8 10 11 15

Input 2:
nums1 = [1,2,7] nums2 = [9,10,17]
Output 2:
1 2 7 9 10 17

Input 3:
nums1 = [-10,-2,7] nums2 = [-3, -1, 7]
Output 3:
-10 -3 -2 -1 7 7

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int parseBracketArray(char *start, char **nextPos, int arr[]) {
    char *bOpen = strchr(start, '[');
    if (!bOpen) return 0;
    char *bClose = strchr(bOpen, ']');
    if (!bClose) return 0;

    int n = 0;
    char *p = bOpen + 1;
    while (p < bClose) {
        while (p < bClose && !isdigit(*p) && *p != '-') p++;
        if (p < bClose) {
            arr[n++] = (int)strtol(p, &p, 10);
        }
    }
    if (nextPos) *nextPos = bClose + 1;
    return n;
}

int main() {
    char buffer[2048];
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;

    int nums1[1000], nums2[1000];
    char *nextPos = NULL;
    int m = parseBracketArray(buffer, &nextPos, nums1);
    int n = 0;
    if (nextPos) {
        n = parseBracketArray(nextPos, NULL, nums2);
    }

    int i = 0, j = 0, first = 1;
    while (i < m && j < n) {
        if (!first) printf(" ");
        first = 0;
        if (nums1[i] <= nums2[j]) {
            printf("%d", nums1[i++]);
        } else {
            printf("%d", nums2[j++]);
        }
    }
    while (i < m) {
        if (!first) printf(" ");
        first = 0;
        printf("%d", nums1[i++]);
    }
    while (j < n) {
        if (!first) printf(" ");
        first = 0;
        printf("%d", nums2[j++]);
    }
    printf("\n");

    return 0;
}
