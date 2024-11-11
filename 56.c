//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char supplier_name[50];
    float price;
} Supplier;

typedef struct {
    char product_name[50];
    int num_suppliers;
    Supplier *suppliers;
    float avg_price;
    char cheapest_supplier[50];
} Product;

void input_data(Product *products, int num_products) {
    for (int i = 0; i < num_products; i++) {
        scanf("%s", products[i].product_name);
        scanf("%d", &products[i].num_suppliers);

        products[i].suppliers = (Supplier *)malloc(products[i].num_suppliers * sizeof(Supplier));

        float total_price = 0;
        float min_price = __FLT_MAX__;
        for (int j = 0; j < products[i].num_suppliers; j++) {
            scanf("%s %f", products[i].suppliers[j].supplier_name, &products[i].suppliers[j].price);
            total_price += products[i].suppliers[j].price;

            // Check if this supplier offers the cheapest price
            if (products[i].suppliers[j].price < min_price) {
                min_price = products[i].suppliers[j].price;
                strcpy(products[i].cheapest_supplier, products[i].suppliers[j].supplier_name);
            }
        }
        products[i].avg_price = total_price / products[i].num_suppliers;
    }
}

void display_results(Product *products, int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("Product: %s\n", products[i].product_name);
        printf("Average Price: %.2f\n", products[i].avg_price);
        printf("Cheapest Supplier: %s\n", products[i].cheapest_supplier);
    }
}

void free_memory(Product *products, int num_products) {
    for (int i = 0; i < num_products; i++) {
        free(products[i].suppliers);
    }
}

int main() {
    int num_products;
    scanf("%d", &num_products);

    Product *products = (Product *)malloc(num_products * sizeof(Product));

    input_data(products, num_products);
    display_results(products, num_products);

    free_memory(products, num_products);
    free(products);

    return 0;
}
