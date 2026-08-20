/*
Q22: Write a program to find profit or loss percentage given cost price and selling price.

Sample Test Cases:
Input 1:
1000 1200
Output 1:
Profit 20%

Input 2:
1000 800
Output 2:
Loss 20%

Input 3:
1000 1000
Output 3:
No Profit No Loss

*/

#include <stdio.h>

int main() {
    double cp, sp;
    if (scanf("%lf %lf", &cp, &sp) == 2) {
        if (sp > cp) {
            double p = ((sp - cp) / cp) * 100.0;
            printf("Profit %g%%\n", p);
        } else if (cp > sp) {
            double l = ((cp - sp) / cp) * 100.0;
            printf("Loss %g%%\n", l);
        } else {
            printf("No Profit No Loss\n");
        }
    }
    return 0;
}
