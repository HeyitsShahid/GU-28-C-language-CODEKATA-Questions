//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

// Function to determine the weight category
const char* get_weight_category(float weight) {
    if (weight > 0 && weight <= 5) {
        return "Lightweight";
    } else if (weight > 5 && weight <= 20) {
        return "Standard";
    } else if (weight > 20 && weight <= 50) {
        return "Heavy";
    } else {
        return "Overweight";
    }
}

// Function to calculate the cost based on weight category, distance, and shipment type
float calculate_cost(const char* category, int distance, const char* type) {
    float rate = 0.0;

    // Determine rate based on shipment type and weight category
    if (strcmp(type, "domestic") == 0) {
        if (strcmp(category, "Lightweight") == 0) rate = 1.0;
        else if (strcmp(category, "Standard") == 0) rate = 1.5;
        else if (strcmp(category, "Heavy") == 0) rate = 2.0;
        else if (strcmp(category, "Overweight") == 0) rate = 3.0;
    } else if (strcmp(type, "international") == 0) {
        if (strcmp(category, "Lightweight") == 0) rate = 2.0;
        else if (strcmp(category, "Standard") == 0) rate = 3.0;
        else if (strcmp(category, "Heavy") == 0) rate = 4.0;
        else if (strcmp(category, "Overweight") == 0) rate = 6.0;
    }

    // Calculate cost
    return distance * rate;
}

// Function to display shipment details
void display_cost(const char* category, const char* type, float cost) {
    printf("%s\n", category);
    printf("%s\n", type);
    printf("%.2f\n", cost);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        float weight;
        int distance;
        char type[15];

        // Input weight, distance, and shipment type
        scanf("%f %d %s", &weight, &distance, type);

        // Determine weight category
        const char* category = get_weight_category(weight);

        // Calculate cost
        float cost = calculate_cost(category, distance, type);

        // Display the result
        display_cost(category, type, cost);
    }

    return 0;
}
