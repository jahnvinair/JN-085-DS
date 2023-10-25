#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  // For the first node, make it point to itself
    } else {
        struct Node* last = (*head)->next;
        while (last->next != (*head)) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  // For the first node, make it point to itself
        *head = newNode;
    } else {
        struct Node* last = (*head)->next;
        while (last->next != (*head)) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Empty circular linked list\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("[%d]->", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("*********CLL Main Menu*********\n");
        printf("===============================================\n");
        printf("1. Insert in beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete node after specified location\n");
        printf("7. Reverse linked list\n");
        printf("8. Concatenate linked lists\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 9:
                display(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
