//Let's Code--Shahid
#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// Define movement directions for 8 possible neighbors
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// Helper function to check if a cell is within bounds and unvisited
bool isSafe(int x, int y, int n, int m, int grid[][MAX], bool visited[][MAX]) {
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && (grid[x][y] == 1 || grid[x][y] == 2));
}

// DFS to mark all cells connected to (x, y) as part of the same island
void dfs(int x, int y, int n, int m, int grid[][MAX], bool visited[][MAX]) {
    visited[x][y] = true;
    // Explore all 8 directions
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isSafe(newX, newY, n, m, grid, visited)) {
            dfs(newX, newY, n, m, grid, visited);
        }
    }
}

// Function to count the number of distinct islands in the grid
int countIslands(int grid[][MAX], int n, int m) {
    bool visited[MAX][MAX] = {false};  // Track visited cells
    int islandCount = 0;

    // Traverse all cells in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Start a new DFS if an unvisited land/bridge cell is found
            if (!visited[i][j] && (grid[i][j] == 1 || grid[i][j] == 2)) {
                dfs(i, j, n, m, grid, visited);
                islandCount++;  // Increment island count for each DFS initiation
            }
        }
    }

    return islandCount;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int grid[MAX][MAX];

    // Input grid values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Calculate the number of islands
    int result = countIslands(grid, n, m);
    printf("%d\n", result);

    return 0;
}
