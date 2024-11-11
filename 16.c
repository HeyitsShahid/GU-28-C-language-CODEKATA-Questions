//Let's Code--Shahid
#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

// Function prototypes
void add_book();
void search_book();
void delete_book();
void display_books();
void exit_program();

int main() {
    int choice;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                delete_book();
                break;
            case 4:
                display_books();
                break;
            case 5:
                exit_program();
                printf("Exiting the program...\n");
                return 0;
            default:
                break;
        }
    }
    return 0;
}

// Function to add a book
void add_book() {
    if (book_count >= MAX_BOOKS) {
        return;
    }

    int id;
    char title[MAX_TITLE_LENGTH];

    if (scanf("%d", &id) != 1) {
        return;
    }

    // Check if ID is positive
    if (id <= 0) {
        return;
    }

    // Check if ID is unique
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            return;
        }
    }

    // Read title
    getchar(); // Clear newline from buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    library[book_count].id = id;
    strncpy(library[book_count].title, title, MAX_TITLE_LENGTH - 1);
    library[book_count].title[MAX_TITLE_LENGTH - 1] = '\0'; // Ensure null termination
    book_count++;
    printf("Book added successfully.\n");
}

// Function to search for a book by ID
void search_book() {
    int id;
    if (scanf("%d", &id) != 1) {
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("Book found: ID=%d, Title=\"%s\"\n", library[i].id, library[i].title);
            return;
        }
    }
    printf("Book with ID=%d not found.\n", id);
}

// Function to delete a book by ID
void delete_book() {
    int id;
    if (scanf("%d", &id) != 1) {
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book with ID=%d not found.\n", id);
}

// Function to display all books
void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
    } else {
        for (int i = 0; i < book_count; i++) {
            printf("Book ID=%d, Title=\"%s\"\n", library[i].id, library[i].title);
        }
    }
}

// Function to exit the program
void exit_program() {
}
