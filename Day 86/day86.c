/*
Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30

*/

#include <stdio.h>
#include <string.h>

enum Operation {
    ADD,
    SUBTRACT,
    MULTIPLY
};

int main() {
    char opStr[50];
    int a = 10, b = 20;
    enum Operation op = ADD;

    if (scanf("%s %d %d", opStr, &a, &b) == 3) {
        if (strcmp(opStr, "ADD") == 0) op = ADD;
        else if (strcmp(opStr, "SUBTRACT") == 0) op = SUBTRACT;
        else if (strcmp(opStr, "MULTIPLY") == 0) op = MULTIPLY;
    }

    switch (op) {
        case ADD:
            printf("%d\n", a + b);
            break;
        case SUBTRACT:
            printf("%d\n", a - b);
            break;
        case MULTIPLY:
            printf("%d\n", a * b);
            break;
    }

    return 0;
}
