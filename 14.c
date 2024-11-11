//Let's Code--Shahid
#include <stdio.h>

int main() {
    int n;
    
    // Input the number of products
    scanf("%d", &n);

    // Validate product count
    if (n < 1 || n > 100) {
        printf("Number of products must be between 1 and 100.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        int raw_material_cost, labor_cost, overhead_cost;
        
        // Input costs for each product
        scanf("%d %d %d", &raw_material_cost, &labor_cost, &overhead_cost);

        // Ensure costs are within specified limits
        if (raw_material_cost < 1000 || raw_material_cost > 1000000 ||
            labor_cost < 1000 || labor_cost > 1000000 ||
            overhead_cost < 1000 || overhead_cost > 1000000) {
            printf("Cost values must be between ₹1,000 and ₹10,00,000.\n");
            return 1;
        }

        // Calculate total production cost
        int total_production_cost = raw_material_cost + labor_cost + overhead_cost;

        // Calculate gross profit as 20% of total production cost
        double gross_profit = total_production_cost * 0.20;

        // Calculate tax deduction
        double tax_deduction;
        if (gross_profit > 100000) {
            tax_deduction = gross_profit * 0.15;
        } else {
            tax_deduction = gross_profit * 0.10;
        }

        // Calculate net profit
        double net_profit = gross_profit - tax_deduction;

        // Determine product status
        char* product_status;
        if (net_profit >= 75000) {
            product_status = "Highly Profitable";
        } else if (net_profit >= 50000) {
            product_status = "Moderately Profitable";
        } else {
            product_status = "Less Profitable";
        }

        // Output the results for each product
        printf("Product %d:\n", i);
        printf("Total Production Cost: ₹%d\n", total_production_cost);
        printf("Gross Profit: ₹%.2lf\n", gross_profit);
        printf("Tax Deduction: ₹%.2lf\n", tax_deduction);
        printf("Net Profit: ₹%.2lf\n", net_profit);
        printf("Product Status: %s\n", product_status);
    }

    return 0;
}
