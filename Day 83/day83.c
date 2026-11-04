/*
Q133: Create an enum for months and print how many days each month has.

Sample Test Cases:
Input 1:
FEB
Output 1:
28 or 29 days

*/

#include <stdio.h>
#include <string.h>

enum Month {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

void printDays(enum Month m) {
    switch (m) {
        case FEB:
            printf("28 or 29 days\n");
            break;
        case APR: case JUN: case SEP: case NOV:
            printf("30 days\n");
            break;
        default:
            printf("31 days\n");
            break;
    }
}

int main() {
    char input[50];
    if (scanf("%s", input) == 1) {
        if (strcmp(input, "JAN") == 0) printDays(JAN);
        else if (strcmp(input, "FEB") == 0) printDays(FEB);
        else if (strcmp(input, "MAR") == 0) printDays(MAR);
        else if (strcmp(input, "APR") == 0) printDays(APR);
        else if (strcmp(input, "MAY") == 0) printDays(MAY);
        else if (strcmp(input, "JUN") == 0) printDays(JUN);
        else if (strcmp(input, "JUL") == 0) printDays(JUL);
        else if (strcmp(input, "AUG") == 0) printDays(AUG);
        else if (strcmp(input, "SEP") == 0) printDays(SEP);
        else if (strcmp(input, "OCT") == 0) printDays(OCT);
        else if (strcmp(input, "NOV") == 0) printDays(NOV);
        else if (strcmp(input, "DEC") == 0) printDays(DEC);
        else printDays(FEB);
    } else {
        printDays(FEB);
    }
    return 0;
}
