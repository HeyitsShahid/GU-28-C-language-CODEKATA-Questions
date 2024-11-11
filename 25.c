//Let's Code--Shahid
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize min and max with extreme values
    int min_element = INT_MAX;
    int max_element = INT_MIN;
    
    // Find the minimum and maximum elements in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Calculate the maximum difference
    int max_diff = abs(max_element - min_element);
    
    printf("%d\n", max_diff);
    
    return 0;
}
