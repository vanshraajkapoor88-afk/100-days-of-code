/*
Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

Sample Test Cases:
Input 1:
Input File (input.txt): Hello World\nC programming
Output 1:
Output File (output.txt): HELLO WORLD\nC PROGRAMMING

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.txt", "rb");
    if (in == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    FILE *out = fopen("output.txt", "wb");
    if (out == NULL) {
        fclose(in);
        printf("Error creating output.txt\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(toupper((unsigned char)ch), out);
    }

    fclose(in);
    fclose(out);

    printf("Converted text written to output.txt\n");
    return 0;
}
