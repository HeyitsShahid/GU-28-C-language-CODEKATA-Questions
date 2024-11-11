//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int R1, C1, R2, C2;

    // Read dimensions of the first matrix
    scanf("%d %d", &R1, &C1);
    
    // Read dimensions of the second matrix
    scanf("%d %d", &R2, &C2);

    // Check if matrices can be multiplied (C1 must equal R2)
    if (C1 != R2) {
        printf("Matrix multiplication is not possible. Incompatible dimensions.\n");
        return 1;  // Exit the program if dimensions are incompatible
    }

    // Dynamically allocate memory for the matrices
    int **A = (int **)malloc(R1 * sizeof(int *));
    int **B = (int **)malloc(R2 * sizeof(int *));
    int **C = (int **)malloc(R1 * sizeof(int *));
    if (!A || !B || !C) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for the individual rows of matrices A, B, and C
    for (int i = 0; i < R1; i++) A[i] = (int *)malloc(C1 * sizeof(int));
    for (int i = 0; i < R2; i++) B[i] = (int *)malloc(C2 * sizeof(int));
    for (int i = 0; i < R1; i++) C[i] = (int *)malloc(C2 * sizeof(int));

    // Read elements of the first matrix A
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read elements of the second matrix B
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform matrix multiplication: C = A * B
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            C[i][j] = 0;  // Initialize result element to 0
            for (int k = 0; k < C1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the resulting matrix C
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < R1; i++) free(A[i]);
    for (int i = 0; i < R2; i++) free(B[i]);
    for (int i = 0; i < R1; i++) free(C[i]);
    free(A);
    free(B);
    free(C);

    return 0;
}
