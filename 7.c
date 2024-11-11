//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

// Union to hold transaction data
union TransactionDetails {
    struct {
        float amount;
        int account_number;
    } deposit;

    struct {
        float amount;
        int account_number;
        char atm_location[51]; // Extra character for null-terminator
    } withdrawal;

    struct {
        float amount;
        int from_account;
        int to_account;
    } transfer;
};

// Enum for transaction types
typedef enum {
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER,
    UNKNOWN
} TransactionType;

// Function to display transaction details
void display_transaction(TransactionType type, union TransactionDetails transaction) {
    switch (type) {
        case DEPOSIT:
            printf("Transaction Type: Deposit\n");
            printf("Amount: %.2f\n", transaction.deposit.amount);
            printf("Account Number: %d\n", transaction.deposit.account_number);
            break;
        case WITHDRAWAL:
            printf("Transaction Type: Withdrawal\n");
            printf("Amount: %.2f\n", transaction.withdrawal.amount);
            printf("Account Number: %d\n", transaction.withdrawal.account_number);
            printf("ATM Location: %s\n", transaction.withdrawal.atm_location);
            break;
        case TRANSFER:
            printf("Transaction Type: Transfer\n");
            printf("Amount: %.2f\n", transaction.transfer.amount);
            printf("From Account Number: %d\n", transaction.transfer.from_account);
            printf("To Account Number: %d\n", transaction.transfer.to_account);
            break;
        default:
            printf("Invalid transaction type.\n");
            break;
    }
}

int main() {
    char transaction_type;
    union TransactionDetails transaction;
    TransactionType type = UNKNOWN;

    // Read transaction type
    scanf(" %c", &transaction_type);

    if (transaction_type == 'D') {
        type = DEPOSIT;
        scanf("%f %d", &transaction.deposit.amount, &transaction.deposit.account_number);
    } else if (transaction_type == 'W') {
        type = WITHDRAWAL;
        scanf("%f %d", &transaction.withdrawal.amount, &transaction.withdrawal.account_number);
        getchar(); // Consume newline character left by previous scanf
        fgets(transaction.withdrawal.atm_location, sizeof(transaction.withdrawal.atm_location), stdin);
        // Remove trailing newline from the ATM location if present
        size_t len = strlen(transaction.withdrawal.atm_location);
        if (len > 0 && transaction.withdrawal.atm_location[len - 1] == '\n') {
            transaction.withdrawal.atm_location[len - 1] = '\0';
        }
    } else if (transaction_type == 'T') {
        type = TRANSFER;
        scanf("%f %d %d", &transaction.transfer.amount, &transaction.transfer.from_account, &transaction.transfer.to_account);
    } else {
        printf("Error: Invalid transaction type.\n");
        return 1;
    }

    // Display the transaction details
    display_transaction(type, transaction);

    return 0;
}
