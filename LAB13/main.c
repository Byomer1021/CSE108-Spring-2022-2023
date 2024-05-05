#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(struct BST* bst, int value) {
    struct Node* newNode = createNode(value);

    if (bst->root == NULL) {
        bst->root = newNode;
        return;
    }

    struct Node* current = bst->root;
    while (1) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = newNode;
                return;
            }
            current = current->left;
        } else if (value > current->value) {
            if (current->right == NULL) {
                current->right = newNode;
                return;
            }
            current = current->right;
        } else {
           
            return;
        }
    }
}

struct Node* searchNode(struct BST* bst, int value) {
    struct Node* current = bst->root;
    while (current != NULL) {
        if (value == current->value) {
            return current;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinValueNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }
    return root;
}

void freeBST(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int getMaxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = getMaxDepth(root->left);
    int rightDepth = getMaxDepth(root->right);
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->value);
        printInorder(root->right);
    }
}

void printPreorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(struct Node* root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->value);
    }
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->value);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

void printMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Add a node\n");
    printf("2. Remove a node\n");
    printf("3. Search for a node\n");
    printf("4. Count total nodes\n");
    printf("5. Get maximum depth\n");
    printf("6. Count leaf nodes\n");
    printf("7. Print the tree\n");
    printf("8. Exit\n");
    printf("Enter your choice (1-8): ");
}

int main() {
    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = NULL;

    int choice, value;
    struct Node* node;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                addNode(bst, value);
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                bst->root = removeNode(bst->root, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                node = searchNode(bst, value);
                if (node != NULL) {
                    printf("Node with value %d found in the BST.\n", value);
                } else {
                    printf("Node with value %d not found in the BST.\n", value);
                }
                break;
            case 4:
                printf("Total number of nodes in the BST: %d\n", countNodes(bst->root));
                break;
            case 5:
                printf("Maximum depth of the BST: %d\n", getMaxDepth(bst->root));
                break;
            case 6:
                printf("Number of leaf nodes in the BST: %d\n", countLeafNodes(bst->root));
                break;
            case 7:
                printf("Choose the traversal method:\n");
                printf("1. In-order\n");
                printf("2. Pre-order\n");
                printf("3. Post-order\n");
                printf("4. Level-order\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &value);
                printf("Binary Search Tree: ");
                switch (value) {
                    case 1:
                        printInorder(bst->root);
                        break;
                    case 2:
                        printPreorder(bst->root);
                        break;
                    case 3:
                        printPostorder(bst->root);
                        break;
                    case 4:
                        printLevelOrder(bst->root);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                printf("\n");
                break;
            case 8:
                freeBST(bst->root);
                free(bst);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
