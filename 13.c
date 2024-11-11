//Let's Code--Shahid
#include <stdio.h>

int main() {
    int savings_balance;
    float current_balance;
    double fixed_deposit_balance;
    double total_balance;

    // Input balances for each account type
    scanf("%d", &savings_balance);
    scanf("%f", &current_balance);
    scanf("%lf", &fixed_deposit_balance);

    // Calculate total balance with type casting for precision
    total_balance = (double)savings_balance + (double)current_balance + fixed_deposit_balance;

    // Output the total balance with the highest precision
    printf("Total Balance: %.2lf\n", total_balance);

    return 0;
}
