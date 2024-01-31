#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product structure
struct Product {
    char name[50];
    int id;
    float price;
    int quantity;
};

// Function to display the menu
void displayMenu() {
    printf("\n===== Retailer Shop Billing System =====\n");
    printf("1. Add Product\n");
    printf("2. Display Bill\n");
    printf("3. Exit\n");
    printf("======================================\n");
}

// Function to add a product to the system
void addProduct(struct Product products[], int *productCount) {
    if (*productCount >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    struct Product newProduct;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    products[*productCount] = newProduct;
    (*productCount)++;

    printf("Product added successfully!\n");
}

// Function to display the bill
void displayBill(struct Product products[], int productCount) {
    if (productCount == 0) {
        printf("No products added to the bill.\n");
        return;
    }

    float totalAmount = 0;

    printf("\n===== Bill =====\n");
    printf("ID\tName\tPrice\tQuantity\tTotal\n");

    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].price,
               products[i].quantity, products[i].price * products[i].quantity);
        totalAmount += products[i].price * products[i].quantity;
    }

    printf("\nTotal Amount: %.2f\n", totalAmount);
}

int main() {
    struct Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                displayBill(products, productCount);
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
