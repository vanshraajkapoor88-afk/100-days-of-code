/*
Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.

Sample Test Cases:
Input 1:
Name: Asha
Roll: 101
Marks: 90
Output 1:
Name: Asha | Roll: 101 | Marks: 90

*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student s;
    strcpy(s.name, "Asha");
    s.roll_no = 101;
    s.marks = 90;

    char tempName[50];
    int tempRoll, tempMarks;

    if (scanf("%s %d %d", tempName, &tempRoll, &tempMarks) == 3) {
        strcpy(s.name, tempName);
        s.roll_no = tempRoll;
        s.marks = tempMarks;
    }

    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
    return 0;
}
