/*
Q132: Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.

Sample Test Cases:
Input 1:
GREEN
Output 1:
Go

*/

#include <stdio.h>
#include <string.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

void checkLight(enum TrafficLight light) {
    switch (light) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
    }
}

int main() {
    char str[50];
    if (scanf("%s", str) == 1) {
        if (strcmp(str, "RED") == 0) checkLight(RED);
        else if (strcmp(str, "YELLOW") == 0) checkLight(YELLOW);
        else if (strcmp(str, "GREEN") == 0) checkLight(GREEN);
        else checkLight(GREEN);
    } else {
        checkLight(GREEN);
    }
    return 0;
}
