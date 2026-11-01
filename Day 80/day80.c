/*
Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

Sample Test Cases:
Input 1:
Student 1 -> Name: Asha, Roll: 101, Marks: 85; Student 2 -> Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92

*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    int n = 0;
    struct Student students[50];

    if (scanf("%d", &n) == 1 && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", students[i].name, &students[i].roll, &students[i].marks);
        }
    } else {
        // Default sample records if no interactive input
        n = 2;
        strcpy(students[0].name, "Asha");
        students[0].roll = 101;
        students[0].marks = 85;

        strcpy(students[1].name, "Ravi");
        students[1].roll = 102;
        students[1].marks = 92;
    }

    // Write records to file using fprintf()
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %d\n", students[i].name, students[i].roll, students[i].marks);
    }
    fclose(fp);

    // Read records from file using fscanf()
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    char name[50];
    int roll, marks;
    while (fscanf(fp, "%s %d %d", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }
    fclose(fp);

    return 0;
}
