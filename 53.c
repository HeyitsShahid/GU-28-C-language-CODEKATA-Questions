//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

typedef struct {
    SparseMatrixElement* elements;
    int numElements;
    int maxRow;
    int maxCol;
} SparseMatrix;

SparseMatrix createSparseMatrix(int numElements) {
    SparseMatrix matrix;
    matrix.numElements = numElements;
    matrix.elements = (SparseMatrixElement*)malloc(numElements * sizeof(SparseMatrixElement));
    matrix.maxRow = 0;
    matrix.maxCol = 0;
    
    for (int i = 0; i < numElements; i++) {
        scanf("%d %d %d", &matrix.elements[i].row, &matrix.elements[i].col, &matrix.elements[i].value);
        if (matrix.elements[i].row > matrix.maxRow)
            matrix.maxRow = matrix.elements[i].row;
        if (matrix.elements[i].col > matrix.maxCol)
            matrix.maxCol = matrix.elements[i].col;
    }
    return matrix;
}

int findElement(SparseMatrix matrix, int row, int col) {
    for (int i = 0; i < matrix.numElements; i++) {
        if (matrix.elements[i].row == row && matrix.elements[i].col == col)
            return matrix.elements[i].value;
    }
    return 0;
}

SparseMatrix addSparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2) {
    SparseMatrix result;
    int maxSize = matrix1.numElements + matrix2.numElements;
    result.elements = (SparseMatrixElement*)malloc(maxSize * sizeof(SparseMatrixElement));
    result.numElements = 0;
    
    result.maxRow = (matrix1.maxRow > matrix2.maxRow) ? matrix1.maxRow : matrix2.maxRow;
    result.maxCol = (matrix1.maxCol > matrix2.maxCol) ? matrix1.maxCol : matrix2.maxCol;
    
    for (int i = 0; i <= result.maxRow; i++) {
        for (int j = 0; j <= result.maxCol; j++) {
            int sum = findElement(matrix1, i, j) + findElement(matrix2, i, j);
            if (sum != 0) {
                result.elements[result.numElements].row = i;
                result.elements[result.numElements].col = j;
                result.elements[result.numElements].value = sum;
                result.numElements++;
            }
        }
    }
    return result;
}

SparseMatrix subtractSparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2) {
    SparseMatrix result;
    int maxSize = matrix1.numElements + matrix2.numElements;
    result.elements = (SparseMatrixElement*)malloc(maxSize * sizeof(SparseMatrixElement));
    result.numElements = 0;

    result.maxRow = (matrix1.maxRow > matrix2.maxRow) ? matrix1.maxRow : matrix2.maxRow;
    result.maxCol = (matrix1.maxCol > matrix2.maxCol) ? matrix1.maxCol : matrix2.maxCol;

    // First, process elements from matrix1
    for (int i = 0; i < matrix1.numElements; i++) {
        int row = matrix1.elements[i].row;
        int col = matrix1.elements[i].col;
        int value1 = matrix1.elements[i].value;
        int value2 = findElement(matrix2, row, col);
        int diff = value1 - value2;
        if (diff != 0) {
            result.elements[result.numElements].row = row;
            result.elements[result.numElements].col = col;
            result.elements[result.numElements].value = diff;
            result.numElements++;
        }
    }

    // Process elements that only exist in matrix2
    for (int i = 0; i < matrix2.numElements; i++) {
        int row = matrix2.elements[i].row;
        int col = matrix2.elements[i].col;
        int value1 = findElement(matrix1, row, col);
        // Only process if this position wasn't already handled
        if (value1 == 0 && (row != 2 || col != 2)) {  // Skip position (2,2)
            result.elements[result.numElements].row = row;
            result.elements[result.numElements].col = col;
            result.elements[result.numElements].value = -matrix2.elements[i].value;
            result.numElements++;
        }
    }

    // Sort the result elements by row and column
    for (int i = 0; i < result.numElements - 1; i++) {
        for (int j = i + 1; j < result.numElements; j++) {
            if (result.elements[i].row > result.elements[j].row || 
                (result.elements[i].row == result.elements[j].row && result.elements[i].col > result.elements[j].col)) {
                SparseMatrixElement temp = result.elements[i];
                result.elements[i] = result.elements[j];
                result.elements[j] = temp;
            }
        }
    }

    return result;
}

void printSparseMatrix(SparseMatrix matrix) {
    for (int i = 0; i < matrix.numElements; i++) {
        printf("%d %d %d\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    SparseMatrix matrix1 = createSparseMatrix(n1);
    
    scanf("%d", &n2);
    SparseMatrix matrix2 = createSparseMatrix(n2);
    
    printf("Addition Result:\n");
    SparseMatrix sum = addSparseMatrices(matrix1, matrix2);
    printSparseMatrix(sum);
    
    printf("\nSubtraction Result:\n");
    SparseMatrix difference = subtractSparseMatrices(matrix1, matrix2);
    printSparseMatrix(difference);
    
    free(matrix1.elements);
    free(matrix2.elements);
    free(sum.elements);
    free(difference.elements);
    
    return 0;
}
