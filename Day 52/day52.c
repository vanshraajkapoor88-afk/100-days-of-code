/*
Q102: Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

Sample Test Cases:
Input 1:
arr = [1, 2, 8, 10, 11, 12, 19], x = 5
Output 1:
2

Input 2:
arr = [1, 2, 8, 10, 11, 12, 19], x = 20
Output 2:
-1

Input 3:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output 3:
0

Input 4:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 2
Output 4:
2

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void parseArrayAndTarget(int arr[], int *n, int *target) {
    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), stdin)) return;

    char *bracketOpen = strchr(buffer, '[');
    while (bracketOpen && (bracketOpen[1] == ']' || (bracketOpen[1] == ' ' && bracketOpen[2] == ']'))) {
        bracketOpen = strchr(bracketOpen + 2, '[');
    }

    if (bracketOpen) {
        char *bracketClose = strchr(bracketOpen, ']');
        if (bracketClose) {
            *n = 0;
            char *p = bracketOpen + 1;
            while (p < bracketClose) {
                while (p < bracketClose && !isdigit(*p) && *p != '-') p++;
                if (p < bracketClose) {
                    arr[(*n)++] = (int)strtol(p, &p, 10);
                }
            }
            if (target) {
                *target = 0;
                p = bracketClose + 1;
                while (*p && !isdigit(*p) && *p != '-') p++;
                if (*p) {
                    *target = (int)strtol(p, &p, 10);
                }
            }
            return;
        }
    }

    // Fallback: whitespace-separated numbers
    char *p = buffer;
    int temp[200], count = 0;
    while (*p) {
        while (*p && !isdigit(*p) && *p != '-') p++;
        if (*p) {
            temp[count++] = (int)strtol(p, &p, 10);
        }
    }
    if (target) {
        if (count >= 2 && count == temp[0] + 2) {
            *n = temp[0];
            for (int i = 0; i < *n; i++) arr[i] = temp[i + 1];
            *target = temp[count - 1];
        } else if (count >= 1) {
            *n = count - 1;
            for (int i = 0; i < *n; i++) arr[i] = temp[i];
            *target = temp[count - 1];
        }
    } else {
        if (count >= 1 && count == temp[0] + 1) {
            *n = temp[0];
            for (int i = 0; i < *n; i++) arr[i] = temp[i + 1];
        } else {
            *n = count;
            for (int i = 0; i < *n; i++) arr[i] = temp[i];
        }
    }
}

int main() {
    int arr[1000], n = 0, x = 0;
    parseArrayAndTarget(arr, &n, &x);

    int ceilIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            ceilIndex = i;
            break;
        }
    }

    printf("%d\n", ceilIndex);
    return 0;
}
