//Let's Code--Shahid
#include <stdio.h>

int maxProductSubarray(int arr[], int n) {
    // Initialize max_prod and min_prod to the first element
    int max_prod = arr[0];
    int min_prod = arr[0];
    int result = arr[0];
    
    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++) {
        int num = arr[i];
        
        // If the current number is negative, swap max_prod and min_prod
        if (num < 0) {
            int temp = max_prod;
            max_prod = min_prod;
            min_prod = temp;
        }
        
        // Update max_prod and min_prod
        max_prod = (num > max_prod * num) ? num : max_prod * num;
        min_prod = (num < min_prod * num) ? num : min_prod * num;
        
        // Update result with the maximum product found so far
        if (max_prod > result) {
            result = max_prod;
        }
    }
    
    return result;
}

void getInputArray(int arr[], int n) {
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);  // Read the size of the array
    
    int arr[n];
    getInputArray(arr, n);  // Populate the array
    
    int result = maxProductSubarray(arr, n);  // Calculate maximum product
    printf("%d\n", result);  // Print the result
    
    return 0;
}
