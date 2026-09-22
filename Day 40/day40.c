/*
Q79: Perform diagonal traversal of a matrix.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/

#include <stdio.h>

int main() {
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2) return 0;

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int first = 1;
    int numDiagonals = rows + cols - 1;
    for (int d = 0; d < numDiagonals; d++) {
        if (d % 2 == 0) {
            int r = (d < rows) ? d : rows - 1;
            int c = d - r;
            while (r >= 0 && c < cols) {
                if (!first) printf(" ");
                printf("%d", matrix[r][c]);
                first = 0;
                r--;
                c++;
            }
        } else {
            int c = (d < cols) ? d : cols - 1;
            int r = d - c;
            while (c >= 0 && r < rows) {
                if (!first) printf(" ");
                printf("%d", matrix[r][c]);
                first = 0;
                r++;
                c--;
            }
        }
    }
    printf("\n");
    return 0;
}
