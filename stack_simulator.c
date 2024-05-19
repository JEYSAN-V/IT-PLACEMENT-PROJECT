#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100

// Page structure
struct Page {
    char title[100];
};

// Global variables
struct Page history[MAX_PAGES];
int top = -1; // Initialize the top of the stack
char currentTitle[100] = ""; // Initialize the current page title

// Function to add a new page title to the stack
void visitPage(const char* title) {
    if (top < MAX_PAGES - 1) {
        strcpy(history[++top].title, title);
        strcpy(currentTitle, title); // Update the current page title
        printf("Visited: %s\n", title);
    } else {
        printf("History is full! Cannot add more pages.\n");
    }
    printf("\n\n\npress enter to continue...");
    getch();
    system("cls");
}

// Function to go back (pop from the stack)
void goBack() {
    if (top >= 1) {
        printf("Going back to: %s\n", history[top - 1].title);
        top--;
        strcpy(currentTitle, history[top].title); // Update the current page title
    } else {
        printf("No previous page to go back to.\n");
    }
    printf("\n\n\npress enter to continue...");
    getch();
    system("cls");
}

// Function to go forward (push back to the stack)
void goForward() {
    if (top < MAX_PAGES - 1 && history[top + 1].title[0] != '\0') {
        printf("Going forward to: %s\n", history[top + 1].title);
        top++;
        strcpy(currentTitle, history[top].title); // Update the current page title
    } else {
        printf("No next page to go forward to.\n");
    }
    printf("\n\n\npress enter to continue...");
    getch();
    system("cls");
}

// Function to display full browsing history
void displayHistory() {
	int i;
    printf("\nBrowsing History:\n");
    for (i = top; i>=0; i--) {
        printf(" %s\n", history[i].title);
    }
    printf("\n\n\npress enter to continue...");
    getch();
    system("cls");
}

// Function to clear browsing history
void clearHistory() {
    top = -1;
    strcpy(currentTitle, ""); // Clear the current page title
    printf("Browsing history cleared.\n");
    printf("\n\n\npress enter to continue...");
    getch();
    system("cls");
}

int main() {
    int choice;

    while (1) {
        printf("\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\tWEB BROWSER\n");
        printf("\t\t\t---------------------------------------\n");
        printf("\nCurrent Page: %s\n", currentTitle); // Display current page title
        printf("\nMenu:\n");
        printf("1. Visit a Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. View History\n");
        printf("5. Clear History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter page title: ");
                scanf(" %[^\n]", currentTitle); // Update current page title
                visitPage(currentTitle);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                clearHistory();
                break;
            case 6:
                printf("Exiting the browser...!\n");
                printf("\n\n\npress enter to continue...");
    			getch();
    			system("cls");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                printf("\n\n\npress enter to continue...");
    			getch();
    			system("cls");
        }
    }

    return 0;
}

