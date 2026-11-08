/*
Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.

Sample Test Cases:
Input 1:
GUEST
Output 1:
Welcome Guest!

*/

#include <stdio.h>
#include <string.h>

enum Role {
    ADMIN,
    USER,
    GUEST
};

void displayMessage(enum Role r) {
    switch (r) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
    }
}

int main() {
    char roleStr[50];
    if (scanf("%s", roleStr) == 1) {
        if (strcmp(roleStr, "ADMIN") == 0) displayMessage(ADMIN);
        else if (strcmp(roleStr, "USER") == 0) displayMessage(USER);
        else if (strcmp(roleStr, "GUEST") == 0) displayMessage(GUEST);
        else displayMessage(GUEST);
    } else {
        displayMessage(GUEST);
    }
    return 0;
}
