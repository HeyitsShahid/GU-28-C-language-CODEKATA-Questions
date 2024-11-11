//Let's Code--Shahid
#include <stdio.h>

int findMaxCapacity(int arr[], int n, int k) {
    // Calculate the sum of the first 'k' elements
    int max_sum = 0;
    for (int i = 0; i < k; i++) {
        max_sum += arr[i];
    }
    
    int current_sum = max_sum;
    int max_index = 0;
    
    // Slide the window from the start of the array to the end
    for (int i = k; i < n; i++) {
        // Update the current sum by sliding the window
        current_sum += arr[i] - arr[i - k];
        
        // If the new sum is greater, update max_sum and max_index
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_index = i - k + 1;
        }
    }
    
    return max_index;
}

void getInputArray(int arr[], int n) {
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);  // Read the size of the array and subarray length
    
    int arr[n];
    getInputArray(arr, n);  // Populate the array
    
    int result = findMaxCapacity(arr, n, k);  // Find the starting index of max capacity subarray
    printf("%d\n", result);  // Print the result
    
    return 0;
}
