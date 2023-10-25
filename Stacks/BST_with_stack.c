#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a stack node
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Function to create a new BST node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Stack functions
struct StackNode* createStackNode(struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return (root == NULL);
}

void push(struct StackNode** root, struct TreeNode* node) {
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = *root;
    *root = stackNode;
}

struct TreeNode* pop(struct StackNode** root) {
    if (isEmpty(*root))
        return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct TreeNode* popped = temp->node;
    free(temp);
    return popped;
}

// BST Insertion
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// BST Deletion
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// BST Traversal
void inorderTraversal(struct TreeNode* root) {
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;
    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right)
            push(&stack, current->right);
        if (current->left)
            push(&stack, current->left);
    }
}

void postorderTraversal(struct TreeNode* root) {
    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, root);
    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left)
            push(&stack1, current->left);
        if (current->right)
            push(&stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        struct TreeNode* current = pop(&stack2);
        printf("%d ", current->data);
    }
}

// Function to display menu
void displayMenu() {
    printf("\n-------------------------\n");
    printf("Binary Search Tree Menu\n");
    printf("-------------------------\n");
    printf("1. Insert a Node\n");
    printf("2. Delete a Node\n");
    printf("3. Inorder Traversal\n");
    printf("4. Preorder Traversal\n");
    printf("5. Postorder Traversal\n");
    printf("6. Exit\n");
    printf("-------------------------\n");
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory
    free(root);

    return 0;
}
