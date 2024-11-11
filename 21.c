//Let's Code--Shahid
#include <stdio.h>

// Recursive function to calculate the total cost of items in the cart
float calculateTotalCost(int items[], int n) {
    if (n == 0) {
        return 0;  // Base case: no items left to add
    }
    // Recursively sum up the current item price and remaining items
    return items[n - 1] + calculateTotalCost(items, n - 1);
}

// Function to apply discount based on the number of items in the cart
float applyDiscount(float totalCost, int itemCount) {
    float discountRate = 0.0;
    if (itemCount >= 1 && itemCount <= 5) {
        discountRate = 0.05;  // 5% discount
    } else if (itemCount >= 6 && itemCount <= 10) {
        discountRate = 0.10;  // 10% discount
    } else if (itemCount > 10) {
        discountRate = 0.15;  // 15% discount
    }
    // Calculate the discount amount and subtract from total cost
    return totalCost * (1 - discountRate);
}

int main() {
    int N;
    scanf("%d", &N);  // Number of items

    int items[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &items[i]);  // Price of each item
    }

    // Calculate the total cost of items in the cart
    float totalCost = calculateTotalCost(items, N);

    // Calculate the final price after applying the discount
    float finalCost = applyDiscount(totalCost, N);

    // Print the final cost rounded to two decimal places
    printf("%.2f\n", finalCost);

    return 0;
}
