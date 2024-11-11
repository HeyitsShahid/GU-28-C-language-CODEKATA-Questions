//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each node in the matrix
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* right;  // Next element in same row
    struct Node* down;   // Next element in same column
} Node;

// Structure for the sparse matrix
typedef struct {
    Node** rowHeaders;   // Array of row header pointers
    Node** colHeaders;   // Array of column header pointers
    int maxRows;        // Maximum rows in matrix
    int maxCols;        // Maximum columns in matrix
    int elementCount;   // Count of non-zero elements
} SparseMatrix;

// Create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

// Initialize sparse matrix
SparseMatrix* createSparseMatrix(int maxRows, int maxCols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    if (!matrix) return NULL;
    
    // Allocate row headers
    matrix->rowHeaders = (Node**)calloc(maxRows, sizeof(Node*));
    if (!matrix->rowHeaders) {
        free(matrix);
        return NULL;
    }
    
    // Allocate column headers
    matrix->colHeaders = (Node**)calloc(maxCols, sizeof(Node*));
    if (!matrix->colHeaders) {
        free(matrix->rowHeaders);
        free(matrix);
        return NULL;
    }
    
    matrix->maxRows = maxRows;
    matrix->maxCols = maxCols;
    matrix->elementCount = 0;
    return matrix;
}

// Insert element into sparse matrix
int insertElement(SparseMatrix* matrix, int row, int col, int value) {
    if (!matrix || row < 0 || row >= matrix->maxRows || 
        col < 0 || col >= matrix->maxCols) return 0;
    
    // If value is 0, treat it as deletion
    if (value == 0) {
        deleteElement(matrix, row, col);
        return 1;
    }
    
    // Create new node
    Node* newNode = createNode(row, col, value);
    if (!newNode) return 0;
    
    // Insert into row list
    if (!matrix->rowHeaders[row] || matrix->rowHeaders[row]->col > col) {
        newNode->right = matrix->rowHeaders[row];
        matrix->rowHeaders[row] = newNode;
    } else {
        Node* current = matrix->rowHeaders[row];
        while (current->right && current->right->col < col) {
            current = current->right;
        }
        // Update existing node if it exists
        if (current->right && current->right->col == col) {
            current->right->value = value;
            free(newNode);
            return 1;
        }
        newNode->right = current->right;
        current->right = newNode;
    }
    
    // Insert into column list
    if (!matrix->colHeaders[col] || matrix->colHeaders[col]->row > row) {
        newNode->down = matrix->colHeaders[col];
        matrix->colHeaders[col] = newNode;
    } else {
        Node* current = matrix->colHeaders[col];
        while (current->down && current->down->row < row) {
            current = current->down;
        }
        newNode->down = current->down;
        current->down = newNode;
    }
    
    matrix->elementCount++;
    return 1;
}

// Delete element from sparse matrix
int deleteElement(SparseMatrix* matrix, int row, int col) {
    if (!matrix || row < 0 || row >= matrix->maxRows || 
        col < 0 || col >= matrix->maxCols) return 0;
    
    // Remove from row list
    Node* temp;
    if (matrix->rowHeaders[row] && matrix->rowHeaders[row]->col == col) {
        temp = matrix->rowHeaders[row];
        matrix->rowHeaders[row] = temp->right;
    } else if (matrix->rowHeaders[row]) {
        Node* current = matrix->rowHeaders[row];
        while (current->right && current->right->col < col) {
            current = current->right;
        }
        if (current->right && current->right->col == col) {
            temp = current->right;
            current->right = temp->right;
        } else {
            return 0;  // Element not found
        }
    } else {
        return 0;  // Element not found
    }
    
    // Remove from column list
    if (matrix->colHeaders[col] && matrix->colHeaders[col]->row == row) {
        matrix->colHeaders[col] = temp->down;
    } else {
        Node* current = matrix->colHeaders[col];
        while (current->down && current->down->row < row) {
            current = current->down;
        }
        if (current->down && current->down->row == row) {
            current->down = temp->down;
        }
    }
    
    free(temp);
    matrix->elementCount--;
    return 1;
}

// Retrieve element from sparse matrix
int retrieveElement(SparseMatrix* matrix, int row, int col) {
    if (!matrix || row < 0 || row >= matrix->maxRows || 
        col < 0 || col >= matrix->maxCols) return 0;
    
    // Search in row list (could also search in column list)
    Node* current = matrix->rowHeaders[row];
    while (current && current->col < col) {
        current = current->right;
    }
    
    if (current && current->col == col) {
        return current->value;
    }
    return 0;  // Element not found or is zero
}

// Free sparse matrix memory
void freeSparseMatrix(SparseMatrix* matrix) {
    if (!matrix) return;
    
    // Free all nodes
    for (int i = 0; i < matrix->maxRows; i++) {
        Node* current = matrix->rowHeaders[i];
        while (current) {
            Node* temp = current;
            current = current->right;
            free(temp);
        }
    }
    
    free(matrix->rowHeaders);
    free(matrix->colHeaders);
    free(matrix);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Create sparse matrix (assuming reasonable maximum dimensions)
    SparseMatrix* matrix = createSparseMatrix(1000, 1000);
    if (!matrix) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    char operation[10];
    int row, col, value;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "INSERT") == 0) {
            scanf("%d %d %d", &row, &col, &value);
            insertElement(matrix, row, col, value);
        }
        else if (strcmp(operation, "DELETE") == 0) {
            scanf("%d %d", &row, &col);
            deleteElement(matrix, row, col);
        }
        else if (strcmp(operation, "RETRIEVE") == 0) {
            scanf("%d %d", &row, &col);
            printf("%d\n", retrieveElement(matrix, row, col));
        }
    }
    
    freeSparseMatrix(matrix);
    return 0;
}
