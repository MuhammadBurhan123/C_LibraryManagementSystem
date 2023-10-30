#include <stdio.h>

int main() {
    int availableBooksQuantity = 50, selectedAction, selectedBook, exit = 0;

    do {
        printf("******** Welcome to Library Management System ********\n\n");
        printf("Please select an option:\n 1 - Borrow Book\n 2 - Return Book\n 3 - Check Book Availability\n 4 - Exit\n\n");
        scanf("%d", &selectedAction);

        switch (selectedAction) {
            case 1:
                printf("How many books do you want to borrow:\n");
                scanf("%d", &selectedBook);

                if (selectedBook < 1 || selectedBook > 5) {
                    printf("Invalid input. You can only borrow between 1 and 5 books at a time.\n");
                    continue;
                }

                if (selectedBook > availableBooksQuantity) {
                    printf("Sorry, there are only %d books available. Cannot borrow %d books.\n", availableBooksQuantity, selectedBook);
                } else {
                    availableBooksQuantity -= selectedBook;
                    printf("Successfully borrowed %d books. Remaining available books: %d\n", selectedBook, availableBooksQuantity);
                }
                break;

            case 2:
                printf("How many books do you want to return:\n");
                scanf("%d", &selectedBook);

                if (selectedBook < 1) {
                    printf("Invalid input. Please enter a valid number of books to return.\n");
                    continue;
                }

                availableBooksQuantity += selectedBook;
                printf("Successfully returned %d books. Remaining available books: %d\n", selectedBook, availableBooksQuantity);
                break;

            case 3:
                printf("Number of available books: %d\n", availableBooksQuantity);
                break;

            case 4:
                exit = 1;
                printf("Exiting Library Management System. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (exit == 0);

    return 0;
}
