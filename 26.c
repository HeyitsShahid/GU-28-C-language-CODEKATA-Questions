//Let's Code--Shahid
#include <stdio.h>

int minFlipsToChessboard(int n, int matrix[][500]) {
    int count_pattern1 = 0;
    int count_pattern2 = 0;

    // Loop through the matrix and compare each cell to the expected patterns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Pattern 1: Start with 1 at (0,0) and alternate
            int expected_pattern1 = (i + j) % 2;
            // Pattern 2: Start with 0 at (0,0) and alternate
            int expected_pattern2 = 1 - expected_pattern1;

            // Count mismatches for both patterns
            if (matrix[i][j] != expected_pattern1) {
                count_pattern1++;
            }
            if (matrix[i][j] != expected_pattern2) {
                count_pattern2++;
            }
        }
    }

    // Return the minimum number of flips required
    return count_pattern1 < count_pattern2 ? count_pattern1 : count_pattern2;
}

int main() {
    int n;
    scanf("%d", &n);

    int matrix[500][500];
    // Read the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate minimum flips
    int result = minFlipsToChessboard(n, matrix);
    printf("%d\n", result);

    return 0;
}
