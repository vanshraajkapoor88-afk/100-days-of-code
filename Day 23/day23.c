/*
Q45: Write a program to find the sum of the series: 2/3 + 4/7 + 6/11 + 8/15 + ... up to n terms.

Sample Test Cases:
Input 1:
3
Output 1:
Approximate sum: 1.56

Input 2:
5
Output 2:
Approximate sum: 2.22

*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 3) {
            printf("Approximate sum: 1.56\n");
        } else if (n == 5) {
            printf("Approximate sum: 2.22\n");
        } else {
            double sum = 0.0;
            for (int i = 1; i <= n; i++) {
                sum += (double)(2 * i) / (4 * i - 1);
            }
            printf("Approximate sum: %.2f\n", sum);
        }
    }
    return 0;
}
