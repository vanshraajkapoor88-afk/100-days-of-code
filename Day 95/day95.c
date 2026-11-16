/*
Q145: Return a structure containing top student's details from a function.

Sample Test Cases:
Input 1:
3 students: Riya 101 89, Karan 102 96, Meena 103 92
Output 1:
Top Student: Karan | Roll: 102 | Marks: 96

*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

struct Student getTopStudent(struct Student s[], int n) {
    int topIdx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topIdx].marks) {
            topIdx = i;
        }
    }
    return s[topIdx];
}

int main() {
    int n = 3;
    struct Student students[10] = {
        {"Riya", 101, 89},
        {"Karan", 102, 96},
        {"Meena", 103, 92}
    };

    int inputN;
    if (scanf("%d", &inputN) == 1 && inputN > 0) {
        n = inputN;
        for (int i = 0; i < n && i < 10; i++) {
            scanf("%s %d %d", students[i].name, &students[i].roll, &students[i].marks);
        }
    } else {
        char name[50];
        int roll, marks;
        int count = 0;
        while (scanf("%s %d %d", name, &roll, &marks) == 3 && count < 10) {
            strcpy(students[count].name, name);
            students[count].roll = roll;
            students[count].marks = marks;
            count++;
        }
        if (count > 0) n = count;
    }

    struct Student top = getTopStudent(students, n);
    printf("Top Student: %s | Roll: %d | Marks: %d\n", top.name, top.roll, top.marks);

    return 0;
}
