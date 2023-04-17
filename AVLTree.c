#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalance(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* createNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* insert(AVLNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

AVLNode* deleteNode(AVLNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right,data);
    }
    else {
if ((root->left == NULL) || (root->right == NULL)) {
AVLNode* temp = root->left ? root->left : root->right;
if (temp == NULL) {
            temp = root;
            root = NULL;
        }
        else {
            *root = *temp;
            free(temp);
        }
    }
    else {
        AVLNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
}

if (root == NULL) {
    return root;
}

root->height = 1 + max(getHeight(root->left), getHeight(root->right));

int balance = getBalance(root);

if (balance > 1 && getBalance(root->left) >= 0) {
    return rightRotate(root);
}

if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

if (balance < -1 && getBalance(root->right) <= 0) {
    return leftRotate(root);
}

if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

return root;
}
void display(AVLNode* root) {
if (root != NULL) {
printf("%d ", root->data);
display(root->left);
display(root->right);
}
}

AVLNode* search(AVLNode* root, int data) {
if (root == NULL || root->data == data) {
return root;
}
if (root->data < data) {
return search(root->right, data);
}
return search(root->left, data);
}

int main() {
AVLNode* root = NULL;
int choice, data;

while (1) {
    printf("\nAVL Tree Operations\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("%d inserted into AVL tree\n", data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("%d deleted from AVL tree\n", data);
            break;
        case 3:
            printf("Enter data to search: ");
            scanf("%d", &data);
            AVLNode* found = search(root, data);
            if (found == NULL) {
                printf("%d not found in AVL tree\n", data);
            }
            else {
                printf("%d found in AVL tree\n", data);
            }
            break;
        case 4:
            if (root == NULL) {
                printf("AVL tree is empty\n");
            }
            else {
                printf("AVL tree contains: ");
                display(root);
                printf("\n");
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
    }
}
}


          
