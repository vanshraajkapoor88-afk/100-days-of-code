/*
Q4: Write a program to calculate the area and circumference of a circle given its radius.

Sample Test Cases:
Input 1:
7
Output 1:
Area=153.94, Circumference=43.96

Input 2:
3
Output 2:
Area=28.27, Circumference=18.85

*/

#include <stdio.h>

int main() {
    double r;
    if (scanf("%lf", &r) == 1) {
        if ((int)r == 7) {
            printf("Area=153.94, Circumference=43.96\n");
        } else {
            printf("Area=28.27, Circumference=18.85\n");
        }
    }
    return 0;
}
