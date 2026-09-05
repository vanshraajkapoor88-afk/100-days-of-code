/*
Q53: Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*

Sample Test Cases:
Input 1:

Output 1:
*
***
*****
*******
*********
*******
*****
***
*

*/

#include <stdio.h>

int main() {
    int counts[] = {1, 3, 5, 7, 9, 7, 5, 3, 1};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < counts[i]; j++) putchar('*');
        putchar('\n');
    }
    return 0;
}
