/*
Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0

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
    int arr[1000], n = 0, k = 0;
    parseArrayAndTarget(arr, &n, &k);

    if (n < k || k <= 0) return 0;

    for (int i = 0; i <= n - k; i++) {
        int firstNeg = 0;
        for (int j = i; j < i + k; j++) {
            if (arr[j] < 0) {
                firstNeg = arr[j];
                break;
            }
        }
        printf("%d%c", firstNeg, (i == n - k) ? '\n' : ' ');
    }

    return 0;
}
