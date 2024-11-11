//Let's Code--Shahid
#include <stdio.h>

// Global variable to keep track of total transactions
int total_transactions = 0;

// Function to initialize account balances
void initialize_accounts(float balances[], int n) {
    for (int i = 0; i < n; i++) {
        balances[i] = 0.0; // Initialize each account with zero balance
    }
}

// Function to handle a transaction
void process_transaction(int account_number, char type, float amount, float balances[], int n) {
    // Static local variable to keep the balance for each account
    static float account_balances[10] = {0.0}; // Initialize to zero

    // Update the account balance on the first call
    if (total_transactions == 0) {
        for (int i = 0; i < n; i++) {
            account_balances[i] = balances[i];
        }
    }

    // Check if account_number is valid
    if (account_number < 1 || account_number > n) {
        return;
    }

    // Handle deposit or withdrawal
    if (type == 'D') {
        account_balances[account_number - 1] += amount;
        printf("Account %d Balance: %.2f\n", account_number, account_balances[account_number - 1]);
    } else if (type == 'W') {
        if (account_balances[account_number - 1] >= amount) {
            account_balances[account_number - 1] -= amount;
            printf("Account %d Balance: %.2f\n", account_number, account_balances[account_number - 1]);
        }
    }

    // Increment the global transaction counter
    total_transactions++;
}

int main() {
    int n; // Number of accounts
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        return 1;
    }

    // Array to store initial balances
    float balances[10];
    for (int i = 0; i < n; i++) {
        scanf("%f", &balances[i]);
        if (balances[i] < 0.01 || balances[i] > 1000000.00) {
            return 1;
        }
    }

    int t; // Number of transactions
    scanf("%d", &t);

    if (t < 1 || t > 50) {
        return 1;
    }

    // Process each transaction
    for (int i = 0; i < t; i++) {
        int account_number;
        char type;
        float amount;

        scanf("%d %c %f", &account_number, &type, &amount);

        if (amount < 0.01 || amount > 1000000.00) {
            continue;
        }

        // Process the transaction
        process_transaction(account_number, type, amount, balances, n);
    }

    // Print the total number of transactions
    printf("Total Transactions: %d\n", total_transactions);

    return 0;
}
//Let's Code--Shahid