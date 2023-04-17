#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3
#define MAX_CHILDREN MAX_KEYS + 1

typedef struct BTreeNode {
    int numKeys;
    int keys[MAX_KEYS];
    struct BTreeNode* children[MAX_CHILDREN];
} BTreeNode;

BTreeNode* createNode() {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->numKeys = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void splitChild(BTreeNode* parent, int index) {
    BTreeNode* leftChild = parent->children[index];
    BTreeNode* rightChild = createNode();
    rightChild->numKeys = MAX_KEYS / 2;
    for (int i = 0; i < rightChild->numKeys; i++) {
        rightChild->keys[i] = leftChild->keys[i + MAX_KEYS / 2];
    }
    if (leftChild->children[0] != NULL) {
        for (int i = 0; i <= MAX_KEYS / 2; i++) {
            rightChild->children[i] = leftChild->children[i + MAX_KEYS / 2];
            leftChild->children[i + MAX_KEYS / 2] = NULL;
        }
    }
    leftChild->numKeys = MAX_KEYS / 2;
    for (int i = parent->numKeys; i > index; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = rightChild;
    for (int i = parent->numKeys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = leftChild->keys[MAX_KEYS / 2];
    parent->numKeys++;
}

void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;
    if (node->children[0] == NULL) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void insert(BTreeNode** root, int key) {
    if (*root == NULL) {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->numKeys = 1;
    } else {
        if ((*root)->numKeys == MAX_KEYS) {
            BTreeNode* newRoot = createNode();
            newRoot->children[0] = *root;
            *root = newRoot;
            splitChild(newRoot, 0);
        }
        insertNonFull(*root, key);
    }
}

void display(BTreeNode* node) {
if (node != NULL) {
int i;
for (i = 0; i < node->numKeys; i++) {
printf("%d ", node->keys[i]);
}
printf("\n");
for (i = 0; i <= node->numKeys; i++) {
display(node->children[i]);
}
}
}

int main() {
BTreeNode* root = NULL;
int choice, key;
do {
printf("Menu:\n");
printf("1. Insert a node\n");
printf("2. Display the B-tree\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the key to insert: ");
scanf("%d", &key);
insert(&root, key);
printf("\nNode inserted !.\n");
break;
case 2:
printf("The B-tree is:\n");
display(root);
break;
case 3:
printf("Thanks for your time\n");
break;
default:
printf("Invalid choice.\n");
}
} while (choice != 3);
return 0;
}
