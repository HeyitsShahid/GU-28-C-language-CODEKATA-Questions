//Let's Code--Shahid
#include <stdio.h>

#define MAX 100

int findMaxPathSum(int matrix[][MAX], int n, int m) {
    int dp[MAX][MAX];
    
    // Initialize the starting point
    dp[0][0] = matrix[0][0];
    
    // Fill the first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }
    
    // Fill the first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }
    
    // Fill the rest of the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = matrix[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }
    
    // The answer is in the bottom-right corner of the dp table
    return dp[n - 1][m - 1];
}

void getInputMatrix(int matrix[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  // Read matrix dimensions
    
    int matrix[MAX][MAX];
    getInputMatrix(matrix, n, m);  // Populate the matrix
    
    int result = findMaxPathSum(matrix, n, m);  // Calculate maximum path sum
    printf("%d\n", result);  // Print the result
    
    return 0;
}
