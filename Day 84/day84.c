/*
Q134: Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.

Sample Test Cases:
Input 1:
FAILURE
Output 1:
Operation failed

*/

#include <stdio.h>
#include <string.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

void printStatus(enum Status s) {
    switch (s) {
        case SUCCESS:
            printf("Operation successful\n");
            break;
        case FAILURE:
            printf("Operation failed\n");
            break;
        case TIMEOUT:
            printf("Operation timed out\n");
            break;
    }
}

int main() {
    char str[50];
    if (scanf("%s", str) == 1) {
        if (strcmp(str, "SUCCESS") == 0) printStatus(SUCCESS);
        else if (strcmp(str, "FAILURE") == 0) printStatus(FAILURE);
        else if (strcmp(str, "TIMEOUT") == 0) printStatus(TIMEOUT);
        else printStatus(FAILURE);
    } else {
        printStatus(FAILURE);
    }
    return 0;
}
