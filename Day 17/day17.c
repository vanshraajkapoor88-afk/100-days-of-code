/*
Q33: Write a program to check if a number is an Armstrong number.

Sample Test Cases:
Input 1:
153
Output 1:
Armstrong

Input 2:
123
Output 2:
Not Armstrong

*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int temp = n, digits = 0;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        temp = n;
        long long sum = 0;
        while (temp > 0) {
            int d = temp % 10;
            sum += (long long)round(pow(d, digits));
            temp /= 10;
        }
        if (sum == n) {
            printf("Armstrong\n");
        } else {
            printf("Not Armstrong\n");
        }
    }
    return 0;
}
