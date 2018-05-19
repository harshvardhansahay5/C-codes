#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
    int data;
    struct node *left, *right;
}*root = NULL;

struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printPostorder(struct node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

void printInorder(struct node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(struct node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int findMax(struct node* root)
{
    if (root == NULL)
        return INT_MIN;
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int findMin(struct node* root)
{
    if (root == NULL)
        return INT_MAX;
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int size(struct node* node)
{
    if (node==NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}

struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void insertelement() {
    int data = 0;
    printf("Enter The Element:\t");
    scanf("%d", &data);
    root = insert(root, data);
}

void menu() {
    printf("================================================================================");
    printf("\n**************************************MENU**************************************\n");
    printf("================================================================================");
    printf("\n1. Insert a new element");
    printf("\n2. Inorder traversal");
    printf("\n3. Preorder traversal");
    printf("\n4. Postorder traversal");
    printf("\n5. Get smallest element");
    printf("\n6. Get largest element");
    printf("\n7. Get total number of nodes");
    printf("\n0. Exit");
}

void choice() {
    int choice;
    do {
        printf("\nEnter Your Choice:\t");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 7);
    switch (choice) {
        case 1: insertelement();
            break;
        case 2: printf("Inorder traversal of binary tree is \n");
            printInorder(root);
            printf("\n");
            break;
        case 3: printf("Preorder traversal of binary tree is \n");
            printPreorder(root);
            printf("\n");
            break;
        case 4: printf("Postorder traversal of binary tree is \n");
            printPostorder(root);
            printf("\n");
            break;
        case 5: printf("Smallest element in the binary tree is %d.", findMin(root));
            printf("\n");
            break;
        case 6: printf("Largest element in the binary tree is %d.", findMax(root));
            printf("\n");
            break;
        case 7: printf("The total number of elements in the binary tree is %d.", size(root));
            printf("\n");
            break;
        case 0: exit(0);
            break;
        default:
            ;
    }
}

int main(void) {
    while (1) {
        menu();
        choice();
    }
    return EXIT_SUCCESS;
}