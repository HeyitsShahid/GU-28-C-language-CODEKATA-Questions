#include <stdio.h>

typedef struct {
    int sum;
    long long product;
    int countGreaterThanThreshold;
} ArrayStats;

// Recursive function to process the 2D array
ArrayStats processArray(int *arr, int rows, int cols, int currentRow, int currentCol, int threshold) {
    ArrayStats stats = {0, 1, 0}; // Initialize sum to 0, product to 1, and count to 0

    // Base case: if we've processed all rows
    if (currentRow >= rows) {
        return stats;
    }

    // Process current element
    int currentValue = *((arr + currentRow * cols) + currentCol);
    
    // Update sum
    stats.sum += currentValue;
    
    // Update product
    stats.product *= currentValue;
    
    // Count elements greater than the threshold
    if (currentValue > threshold) {
        stats.countGreaterThanThreshold++;
    }

    // Move to next element
    if (currentCol + 1 < cols) {
        // Recursive call to process the next column in the same row
        ArrayStats temp = processArray(arr, rows, cols, currentRow, currentCol + 1, threshold);
        stats.sum += temp.sum;
        stats.product *= temp.product;
        stats.countGreaterThanThreshold += temp.countGreaterThanThreshold;
    } else {
        // Recursive call to process the next row (reset column index to 0)
        ArrayStats temp = processArray(arr, rows, cols, currentRow + 1, 0, threshold);
        stats.sum += temp.sum;
        stats.product *= temp.product;
        stats.countGreaterThanThreshold += temp.countGreaterThanThreshold;
    }

    return stats;
}

int main() {
    int rows, cols, threshold;

    // Input for the dimensions of the 2D array and array elements
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];  // Declaring the 2D array

    // Input the elements of the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Input the threshold value
    scanf("%d", &threshold);

    // Process the array recursively
    ArrayStats result = processArray((int *)arr, rows, cols, 0, 0, threshold);

    // Output the results
    printf("Sum: %d\n", result.sum);
    printf("Product: %lld\n", result.product);
    printf("Count greater than %d: %d\n", threshold, result.countGreaterThanThreshold);

    return 0;

