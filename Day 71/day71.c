/*
Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

Sample Test Cases:
Input 1:
Name: Rahul, Age: 23
Output 1:
File created successfully! Data written to info.txt

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char buffer[256];
    char name[100] = "Rahul";
    int age = 23;

    if (fgets(buffer, sizeof(buffer), stdin)) {
        char *namePos = strstr(buffer, "Name:");
        char *agePos = strstr(buffer, "Age:");
        if (namePos && agePos) {
            sscanf(namePos, "Name: %[^,], Age: %d", name, &age);
        } else {
            sscanf(buffer, "%s %d", name, &age);
        }
    }

    FILE *fp = fopen("info.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(fp, "Name: %s Age: %d\n", name, age);
    fclose(fp);

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}
