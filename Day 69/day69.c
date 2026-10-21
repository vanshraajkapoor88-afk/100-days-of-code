/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1

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
    int nums[1000], n = 0;
    parseArrayAndTarget(nums, &n, NULL);

    int seen[10000] = {0};
    int repeated = -1;

    for (int i = 0; i < n; i++) {
        if (seen[nums[i]]) {
            repeated = nums[i];
            break;
        }
        seen[nums[i]] = 1;
    }

    printf("%d\n", repeated);
    return 0;
}
