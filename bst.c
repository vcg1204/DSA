#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node*create(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countExternalNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

int countInternalNodes(struct Node* root) {
    return countNodes(root) - countExternalNodes(root);
}

void mirror(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Mirror left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int data;

    printf("Enter data for the binary tree (enter -1 to stop):\n");

    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;
        root = insert(root, data);
    }

    int treeHeight = height(root);
    int treeDepth = treeHeight - 1; // Depth is height - 1
    printf("Height of the tree: %d\n", treeHeight);
    printf("Depth of the tree: %d\n", treeDepth);

    int totalNodes = countNodes(root);
    int externalNodes = countExternalNodes(root);
    int internalNodes = countInternalNodes(root);

    printf("Total nodes: %d\n", totalNodes);
    printf("External nodes: %d\n", externalNodes);
    printf("Internal nodes: %d\n", internalNodes);

    printf("Original inorder traversal: ");
    inorderTraversal(root);

    mirror(root);

    printf("\nMirrored inorder traversal: ");
    inorderTraversal(root);
    
    printf("\nInorder traversal: ");
    inorderTraversal(root);

    printf("\nPreorder traversal: ");
    preorderTraversal(root);

    printf("\nPostorder traversal: ");
    postorderTraversal(root);

    return 0;
}