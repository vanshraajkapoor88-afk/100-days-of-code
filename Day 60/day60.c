/*
Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2

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
        int maxVal = arr[i];
        for (int j = i + 1; j < i + k; j++) {
            if (arr[j] > maxVal) maxVal = arr[j];
        }
        printf("%d%c", maxVal, (i == n - k) ? '\n' : ' ');
    }

    return 0;
}
