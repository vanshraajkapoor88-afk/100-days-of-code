/*
Q50: Write a program to print the following pattern:
*****
 ****
  ***
   **
    *

Sample Test Cases:
Input 1:

Output 1:
*****
 ****
  ***
   **
    *

Input 2:

Output 2:
Note: Spaces indicate indentation.

*/

#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int s = 0; s < i; s++) putchar(' ');
        for (int j = 0; j < 5 - i; j++) putchar('*');
        putchar('\n');
    }
    return 0;
}
