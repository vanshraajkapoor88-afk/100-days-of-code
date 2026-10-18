/*
Q116: Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j in the array such that nums[i] + nums[j] equals the target. Assume exactly one solution exists and return the indices in any order. Print the two indices separated by a space as output. If no solution exists, print "-1 -1".

Sample Test Cases:
Input 1:
nums = [2,7,11,15], target = 9
Output 1:
0 1

Input 2:
nums = [3,2,4], target = 6
Output 2:
1 2

Input 3:
nums = [3,3], target = 6
Output 3:
0 1

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
    int nums[1000], n = 0, target = 0;
    parseArrayAndTarget(nums, &n, &target);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("-1 -1\n");
    return 0;
}
