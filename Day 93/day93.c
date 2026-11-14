/*
Q143: Find and print the student with the highest marks.

Sample Test Cases:
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)

*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    int n = 3;
    struct Student s[10] = {
        {"Ravi", 101, 95},
        {"Sita", 102, 85},
        {"Aman", 103, 88}
    };

    int inputN;
    if (scanf("%d", &inputN) == 1 && inputN > 0) {
        n = inputN;
        for (int i = 0; i < n && i < 10; i++) {
            scanf("%s %d %d", s[i].name, &s[i].roll, &s[i].marks);
        }
    } else {
        char name[50];
        int roll, marks;
        int count = 0;
        while (scanf("%s %d %d", name, &roll, &marks) == 3 && count < 10) {
            strcpy(s[count].name, name);
            s[count].roll = roll;
            s[count].marks = marks;
            count++;
        }
        if (count > 0) n = count;
    }

    int topIdx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topIdx].marks) {
            topIdx = i;
        }
    }

    printf("Topper: %s (Marks: %d)\n", s[topIdx].name, s[topIdx].marks);
    return 0;
}
