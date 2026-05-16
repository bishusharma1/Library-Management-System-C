#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_ID 20
#define MAX_NAME 100
#define MAX_BORROWED 10

struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char ISBN[20];
    int isBorrowed;
    struct Book* next;
};

struct User {
    char name[MAX_NAME];
    char ID[MAX_ID];
    struct Book* borrowedBooks[MAX_BORROWED];
    int borrowedCount;
    struct User* next;
};

// Book management
void addBook(struct Book** head);
void displayBooks(struct Book* head);
struct Book* searchBook(struct Book* head, const char title[]);

// User management
void addUser(struct User** head);
struct User* findUser(struct User* head, const char ID[]);

// Borrow/Return logic
void borrowBook(struct Book* books, struct User* users);
void returnBook(struct Book* books, struct User* users);
void displayUserBooks(struct User* users);

// Helper
void clearInputBuffer();

int main() {
    struct Book* bookHead = NULL;
    struct User* userHead = NULL;
    int choice;

    while (1) {
        printf("\n--- Library Management Menu ---\n");
        printf("1. Add Book\n2. Display Books\n3. Add User\n");
        printf("4. Borrow Book\n5. Return Book\n6. Display User's Borrowed Book\n7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1: addBook(&bookHead); break;
            case 2: displayBooks(bookHead); break;
            case 3: addUser(&userHead); break;
            case 4: borrowBook(bookHead, userHead); break;
            case 5: returnBook(bookHead, userHead); break;
            case 6: displayUserBooks(userHead); break;
            case 7: printf("Exiting... Thank you!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Utility
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addBook(struct Book** head) {
    struct Book* newBook = malloc(sizeof(struct Book));
    if (!newBook) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Book Title: ");
    fgets(newBook->title, MAX_TITLE, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0;

    printf("Enter Book Author: ");
    fgets(newBook->author, MAX_AUTHOR, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0;

    printf("Enter ISBN: ");
    fgets(newBook->ISBN, 20, stdin);
    newBook->ISBN[strcspn(newBook->ISBN, "\n")] = 0;

    newBook->isBorrowed = 0;
    newBook->next = *head;
    *head = newBook;

    printf("Book added successfully.\n");
}

void displayBooks(struct Book* head) {
    if (!head) {
        printf("No books in library.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    while (head) {
        printf("Title: %s | Author: %s | ISBN: %s | Status: %s\n",
               head->title, head->author, head->ISBN,
               head->isBorrowed ? "Borrowed" : "Available");
        head = head->next;
    }
}

void addUser(struct User** head) {
    struct User* newUser = malloc(sizeof(struct User));
    if (!newUser) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter User Name: ");
    fgets(newUser->name, MAX_NAME, stdin);
    newUser->name[strcspn(newUser->name, "\n")] = 0;

    printf("Enter User ID: ");
    fgets(newUser->ID, MAX_ID, stdin);
    newUser->ID[strcspn(newUser->ID, "\n")] = 0;

    newUser->borrowedCount = 0;
    newUser->next = *head;
    *head = newUser;

    printf("User added successfully.\n");
}

struct Book* searchBook(struct Book* head, const char title[]) {
    while (head) {
        if (strcmp(head->title, title) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

struct User* findUser(struct User* head, const char ID[]) {
    while (head) {
        if (strcmp(head->ID, ID) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void borrowBook(struct Book* books, struct User* users) {
    char title[MAX_TITLE], userID[MAX_ID];
    printf("Enter Book Title to Borrow: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = 0;

    printf("Enter User ID: ");
    fgets(userID, MAX_ID, stdin);
    userID[strcspn(userID, "\n")] = 0;

    struct Book* book = searchBook(books, title);
    if (!book) {
        printf("Book not found.\n");
        return;
    }
    if (book->isBorrowed) {
        printf("Book is already borrowed.\n");
        return;
    }

    struct User* user = findUser(users, userID);
    if (!user) {
        printf("User not found.\n");
        return;
    }

    if (user->borrowedCount >= MAX_BORROWED) {
        printf("User has reached max borrow limit.\n");
        return;
    }

    user->borrowedBooks[user->borrowedCount++] = book;
    book->isBorrowed = 1;

    printf("Book borrowed successfully by %s.\n", user->name);
}

void returnBook(struct Book* books, struct User* users) {
    char title[MAX_TITLE], userID[MAX_ID];
    printf("Enter Book Title to Return: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = 0;

    printf("Enter User ID: ");
    fgets(userID, MAX_ID, stdin);
    userID[strcspn(userID, "\n")] = 0;

    struct User* user = findUser(users, userID);
    if (!user) {
        printf("User not found.\n");
        return;
    }

    for (int i = 0; i < user->borrowedCount; i++) {
        if (strcmp(user->borrowedBooks[i]->title, title) == 0) {
            user->borrowedBooks[i]->isBorrowed = 0;
            for (int j = i; j < user->borrowedCount - 1; j++)
                user->borrowedBooks[j] = user->borrowedBooks[j + 1];
            user->borrowedCount--;
            printf("Book returned successfully.\n");
            return;
        }
    }
    printf("Book not found in user's borrowed list.\n");
}

void displayUserBooks(struct User* users) {
    char userID[MAX_ID];
    printf("Enter User ID to View Borrowed Book: ");
    fgets(userID, MAX_ID, stdin);
    userID[strcspn(userID, "\n")] = 0;

    struct User* user = findUser(users, userID);
    if (!user) {
        printf("User not found.\n");
        return;
    }

    printf("\nBooks borrowed by %s:\n", user->name);
    if (user->borrowedCount == 0) {
        printf("No books borrowed.\n");
    } else {
        for (int i = 0; i < user->borrowedCount; i++) {
            printf("Title: %s | Author: %s\n", user->borrowedBooks[i]->title, user->borrowedBooks[i]->author);
        }
    }
}