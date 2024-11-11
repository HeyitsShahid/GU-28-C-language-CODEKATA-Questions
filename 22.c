//Let's Code--Shahid
#include <stdio.h>

// Function to calculate the base bonus based on performance score
float calculateBaseBonus(float performanceScore) {
    return performanceScore * 50;
}

// Function to calculate additional bonus based on work hours
float calculateAdditionalBonus(float workHours) {
    return workHours * 10;
}

// Function to apply adjustment based on employee type
float applyAdjustment(float bonus, char employeeType) {
    if (employeeType == 'P') {
        // Part-time employee, apply a 5% reduction
        return bonus * 0.95;
    }
    // Full-time employee, no adjustment
    return bonus;
}

int main() {
    int N;
    scanf("%d", &N);  // Number of employees

    for (int i = 0; i < N; i++) {
        float performanceScore, workHours;
        char employeeType;
        scanf("%f %f %c", &performanceScore, &workHours, &employeeType);

        // Calculate base bonus and additional bonus
        float baseBonus = calculateBaseBonus(performanceScore);
        float additionalBonus = calculateAdditionalBonus(workHours);

        // Calculate total bonus before adjustment
        float totalBonus = baseBonus + additionalBonus;

        // Apply adjustment based on employee type
        float finalBonus = applyAdjustment(totalBonus, employeeType);

        // Print the final bonus rounded to two decimal places
        printf("%.2f\n", finalBonus);
    }

    return 0;
}
