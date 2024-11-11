//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product *inventory = NULL;
int inventorySize = 0;

// Function to add a new product
void addProduct(int id, const char *name, int quantity, float price) {
    inventorySize++;
    inventory = realloc(inventory, inventorySize * sizeof(Product));
    
    inventory[inventorySize - 1].id = id;
    strncpy(inventory[inventorySize - 1].name, name, MAX_NAME_LENGTH);
    inventory[inventorySize - 1].quantity = quantity;
    inventory[inventorySize - 1].price = price;
}

// Function to update product quantity
void updateProduct(int id, int quantity) {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity = quantity;
            printf("Product updated successfully\n");
            return;
        }
    }
    printf("Product not found\n");
}

// Function to calculate total inventory value
void calculateTotalInventoryValue() {
    float total = 0.0;
    for (int i = 0; i < inventorySize; i++) {
        total += inventory[i].quantity * inventory[i].price;
    }
    printf("%.2f\n", total);
}

// Function to remove a product
void removeProduct(int id) {
    int index = -1;
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Product not found\n");
        return;
    }
    
    // Shift elements to remove the product
    for (int i = index; i < inventorySize - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    inventorySize--;
    inventory = realloc(inventory, inventorySize * sizeof(Product));
    printf("Product removed successfully\n");
}

// Function to list all products
void listAllProducts() {
    for (int i = 0; i < inventorySize; i++) {
        printf("%d \"%s\" %d %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);

        if (strcmp(operation, "ADD") == 0) {
            int id, quantity;
            float price;
            char name[MAX_NAME_LENGTH];
            scanf("%d \"%[^\"]\" %d %f", &id, name, &quantity, &price);
            addProduct(id, name, quantity, price);
        } else if (strcmp(operation, "UPDATE") == 0) {
            int id, quantity;
            scanf("%d %d", &id, &quantity);
            updateProduct(id, quantity);
        } else if (strcmp(operation, "REMOVE") == 0) {
            int id;
            scanf("%d", &id);
            removeProduct(id);
        } else if (strcmp(operation, "TOTAL") == 0) {
            calculateTotalInventoryValue();
        } else if (strcmp(operation, "LIST") == 0) {
            listAllProducts();
        }
    }

    free(inventory); // Free dynamically allocated memory
    return 0;
}
