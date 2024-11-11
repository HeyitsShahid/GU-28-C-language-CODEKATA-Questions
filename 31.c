//Let's Code--Shahid
#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int d, char dir) {
    // Normalize the rotation steps
    d = d % n;
    
    if (dir == 'L') {
        // Left rotation
        reverse(arr, 0, d - 1);        // Reverse first d elements
        reverse(arr, d, n - 1);        // Reverse remaining n - d elements
        reverse(arr, 0, n - 1);        // Reverse the entire array
    } else if (dir == 'R') {
        // Right rotation
        reverse(arr, n - d, n - 1);    // Reverse last d elements
        reverse(arr, 0, n - d - 1);    // Reverse first n - d elements
        reverse(arr, 0, n - 1);        // Reverse the entire array
    }
}

void getInputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n, d;
    char dir;
    
    scanf("%d %d", &n, &d);    // Read array size and rotation steps
    int arr[n];
    
    getInputArray(arr, n);      // Populate the array
    scanf(" %c", &dir);         // Read rotation direction
    
    rotateArray(arr, n, d, dir);  // Perform the rotation
    
    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
