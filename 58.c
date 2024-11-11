//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

typedef struct {
    float balance;
    float interestRate;
} Savings;

typedef struct {
    float balance;
    float overdraftLimit;
} Checking;

typedef union {
    Savings savings;
    Checking checking;
} AccountDetails;

typedef struct {
    char accountHolderName[50];
    int accountType;  // 1 for Savings, 2 for Checking
    AccountDetails details;
} BankAccount;

void displayAccount(BankAccount account) {
    if (account.accountType == 1) {
        printf("Savings Account Balance: %.2f\n", account.details.savings.balance);
        printf("Annual Interest Rate: %.2f%%\n", account.details.savings.interestRate);
    } else if (account.accountType == 2) {
        printf("Checking Account Balance: %.2f\n", account.details.checking.balance);
        printf("Overdraft Limit: %.2f\n", account.details.checking.overdraftLimit);
    } else {
        printf("Invalid account type.\n");
    }
}

int main() {
    BankAccount account;

    // Input for account holder's name
    fgets(account.accountHolderName, sizeof(account.accountHolderName), stdin);
    account.accountHolderName[strcspn(account.accountHolderName, "\n")] = '\0';  // Remove newline

    // Input for account type
    scanf("%d", &account.accountType);

    // Input details based on account type
    if (account.accountType == 1) {
        // Savings Account
        scanf("%f %f", &account.details.savings.balance, &account.details.savings.interestRate);
    } else if (account.accountType == 2) {
        // Checking Account
        scanf("%f %f", &account.details.checking.balance, &account.details.checking.overdraftLimit);
    } else {
        printf("Invalid account type.\n");
        return 1;
    }

    displayAccount(account);

    return 0;
}
