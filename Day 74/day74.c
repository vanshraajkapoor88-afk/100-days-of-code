/*
Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

Sample Test Cases:
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char source[100] = "source.txt";
    char dest[100] = "destination.txt";

    char line[256];
    if (fgets(line, sizeof(line), stdin)) {
        char s[100], d[100];
        if (sscanf(line, "%s %s", s, d) == 2) {
            strcpy(source, s);
            strcpy(dest, d);
        }
    }

    FILE *srcFp = fopen(source, "rb");
    if (srcFp == NULL) {
        printf("Error opening source file!\n");
        return 1;
    }

    FILE *destFp = fopen(dest, "wb");
    if (destFp == NULL) {
        fclose(srcFp);
        printf("Error creating destination file!\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(srcFp)) != EOF) {
        fputc(ch, destFp);
    }

    fclose(srcFp);
    fclose(destFp);

    printf("File copied successfully to %s\n", dest);
    return 0;
}
