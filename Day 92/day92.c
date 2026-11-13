/*
Q142: Store details of 5 students in an array of structures and print all.

Sample Test Cases:
Input 1:
Details of 5 students (Name, Roll, Marks)
Output 1:
Tabular list of all 5 students with their details

*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    struct Student s[5] = {
        {"Asha", 101, 85},
        {"Ravi", 102, 92},
        {"Sita", 103, 88},
        {"Aman", 104, 78},
        {"Neha", 105, 95}
    };

    for (int i = 0; i < 5; i++) {
        if (scanf("%s %d %d", s[i].name, &s[i].roll, &s[i].marks) != 3) {
            break;
        }
    }

    printf("%-10s %-10s %-10s\n", "Name", "Roll", "Marks");
    printf("------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-10s %-10d %-10d\n", s[i].name, s[i].roll, s[i].marks);
    }

    return 0;
}
