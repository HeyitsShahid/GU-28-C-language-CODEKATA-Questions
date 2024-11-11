//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to check for integer overflow in addition
int safeAdd(int a, int b, int *result) {
    if (b > 0 && a > INT_MAX - b) return 0;
    if (b < 0 && a < INT_MIN - b) return 0;
    *result = a + b;
    return 1;
}

int processTransaction(int balance, char *op, char *value) {
    int amount;
    double factor;
    int newBalance;
    
    if (strcmp(op, "+=") == 0) {
        amount = atoi(value);
        if (!safeAdd(balance, amount, &newBalance)) return balance;
        return newBalance;
    }
    else if (strcmp(op, "-=") == 0) {
        amount = atoi(value);
        if (!safeAdd(balance, -amount, &newBalance)) return balance;
        if (newBalance < 0) return balance;
        return newBalance;
    }
    else if (strcmp(op, "*=") == 0) {
        factor = atof(value);
        double temp = balance * factor;
        if (temp > INT_MAX || temp < INT_MIN) return balance;
        return (int)temp;
    }
    else if (strcmp(op, "/=") == 0) {
        factor = atof(value);
        if (factor == 0) return balance;
        return (int)(balance / factor);
    }
    else if (strcmp(op, "%=") == 0) {
        amount = atoi(value);
        if (amount == 0) return balance;
        return balance % amount;
    }
    else if (strcmp(op, "&=") == 0) {
        amount = atoi(value);
        return balance & amount;
    }
    else if (strcmp(op, "|=") == 0) {
        amount = atoi(value);
        return balance | amount;
    }
    else if (strcmp(op, "^=") == 0) {
        amount = atoi(value);
        return balance ^ amount;
    }
    else if (strcmp(op, "<<=") == 0) {
        amount = atoi(value);
        if (amount < 0 || amount >= 32) return balance;
        return balance << amount;
    }
    else if (strcmp(op, ">>=") == 0) {
        amount = atoi(value);
        if (amount < 0 || amount >= 32) return balance;
        return balance >> amount;
    }
    return balance;
}

int main() {
    int balance;
    char op[5];
    char value[20];
    
    scanf("%d", &balance);
    
    while (1) {
        scanf("%s", op);
        if (op[0] == 'q') break;
        
        scanf("%s", value);
        balance = processTransaction(balance, op, value);
    }
    
    printf("Final Balance: %d\n", balance);
    return 0;
}
