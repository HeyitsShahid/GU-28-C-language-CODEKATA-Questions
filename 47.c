//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

// Function to transpose the matrix
void transpose_matrix(int **matrix, int m, int n) {
    // Create a new matrix to store the transposed matrix
    int **transposed = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        transposed[i] = (int *)malloc(m * sizeof(int));
    }

    // Transpose the matrix (swap rows and columns)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the transposed matrix
    for (int i = 0; i < n; i++) {
        free(transposed[i]);
    }
    free(transposed);
}

int main() {
    int m, n;

    // Read the number of rows and columns
    scanf("%d %d", &m, &n);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the matrix with the product of indices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * j;
        }
    }

    // Call the transpose function to transpose and print the matrix
    transpose_matrix(matrix, m, n);

    // Free the memory allocated for the original matrix
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
