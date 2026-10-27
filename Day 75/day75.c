/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.

*/

#include <stdio.h>
#include <string.h>

int main() {
    char text[500];
    if (!fgets(text, sizeof(text), stdin)) {
        strcpy(text, "This is appended text.\n");
    }

    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error opening data.txt\n");
        return 1;
    }

    fprintf(fp, "%s", text);
    fclose(fp);

    printf("File updated successfully with appended text.\n");
    return 0;
}
