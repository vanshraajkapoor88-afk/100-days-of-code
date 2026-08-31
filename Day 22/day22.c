/*
Q43: Write a program to check if a number is a strong number.

Sample Test Cases:
Input 1:
145
Output 1:
Strong number

Input 2:
123
Output 2:
Not strong number

*/

#include <stdio.h>

int fact(int d) {
    int f = 1;
    for (int i = 2; i <= d; i++) f *= i;
    return f;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int temp = n, sum = 0;
        while (temp > 0) {
            sum += fact(temp % 10);
            temp /= 10;
        }
        if (sum == n) {
            printf("Strong number\n");
        } else {
            printf("Not strong number\n");
        }
    }
    return 0;
}
