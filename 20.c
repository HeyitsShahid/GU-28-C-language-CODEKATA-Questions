//Let's Code--Shahid
#include <stdio.h>

// Function to calculate the total cost of an order
float calculateTotalCost(float prices[], int quantities[], int n) {
    float totalCost = 0.0;
    for (int i = 0; i < n; i++) {
        totalCost += prices[i] * quantities[i];
    }
    return totalCost;
}

// Function to apply discount based on total cost
float applyDiscount(float totalCost) {
    if (totalCost >= 50 && totalCost <= 100) {
        return totalCost * 0.10;  // 10% discount
    } else if (totalCost > 100) {
        return totalCost * 0.20;  // 20% discount
    } else {
        return 0.0;  // No discount
    }
}

// Function to calculate the final price after discount
float finalPriceAfterDiscount(float totalCost) {
    float discount = applyDiscount(totalCost);
    return totalCost - discount;
}

int main() {
    int N;
    scanf("%d", &N);  // Number of orders

    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);  // Number of items in the order

        float prices[M];
        int quantities[M];

        // Read prices and quantities for each item in the order
        for (int j = 0; j < M; j++) {
            scanf("%f %d", &prices[j], &quantities[j]);
        }

        // Calculate total cost
        float totalCost = calculateTotalCost(prices, quantities, M);

        // Calculate final price after discount
        float finalPrice = finalPriceAfterDiscount(totalCost);

        // Print the final price rounded to two decimal places
        printf("%.2f\n", finalPrice);
    }

    return 0;
}
