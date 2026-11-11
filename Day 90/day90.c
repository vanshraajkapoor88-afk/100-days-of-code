/*
Q140: Define a struct with enum Gender and print person's gender.

Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male

*/

#include <stdio.h>
#include <string.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    char name[50];
    enum Gender gender;
};

int main() {
    struct Person p;
    strcpy(p.name, "Alex");
    p.gender = MALE;

    char input[50];
    if (scanf("%s", input) == 1) {
        if (strstr(input, "FEMALE") || strstr(input, "Female")) {
            p.gender = FEMALE;
        } else if (strstr(input, "OTHER") || strstr(input, "Other")) {
            p.gender = OTHER;
        } else {
            p.gender = MALE;
        }
    }

    if (p.gender == MALE) {
        printf("Male\n");
    } else if (p.gender == FEMALE) {
        printf("Female\n");
    } else {
        printf("Other\n");
    }

    return 0;
}
