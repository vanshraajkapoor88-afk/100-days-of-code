/*
Q62: Reverse an array without taking extra space.

Sample Test Cases:
Input 1:
4
1 2 3 4
Output 1:
4 3 2 1

*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        for (int i = 0; i < n; i++) {
            printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
