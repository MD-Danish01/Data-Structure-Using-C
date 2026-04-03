/*
Write a C program to create a Binary Search Tree (BST), and perform insertion, search, inorder, pre-order, and post-order traversals.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNde(int data){
    Node *newNode = (Node *) malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed.\n\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data){
    if(root == NULL){
        return createNde(data);
    }
    
    if(data == root->data){
        printf("\nduplicate key is %d, all nodes in BST should be unique.\n\n", data);
    }else if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void preorderTreverse(Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTreverse(root->left);
    preorderTreverse(root->right);
}

void inorderTreverse(Node *root){
    if(root == NULL){
        return;
    }
    inorderTreverse(root->left);
    printf("%d ", root->data);
    inorderTreverse(root->right);
}

void postorderTreverse(Node *root){
    if(root == NULL){
        return;
    }
    postorderTreverse(root->left);
    postorderTreverse(root->right);
    printf("%d ", root->data);
}

void search(Node *root, int key){
    int isFound = 0;
    if(root == NULL){
        printf("\nkey %d is not found in BST.\n", key);
        return;
    }

    if(key == root->data){
        printf("\nkey %d is found in BST.\n", key);
        return;
    }else if(key < root->data){
        search(root->left, key);
    }else if(key > root->data){
        search(root->right, key);
    }
}

int main(){
    Node *root = NULL;

    root = insert(root, 10);
    
    insert(root, 12);
    insert(root, 3);
    insert(root, 8);
    insert(root, 17);
    insert(root, 3);
    insert(root, 11);
    insert(root, 9);
    insert(root, 2);
    insert(root, 7);

    printf("preorder treversing to BST.\n");
    preorderTreverse(root);
    printf("\n\n");
    
    printf("inorder treversing to BST.\n");
    inorderTreverse(root);
    printf("\n\n");

    printf("postorder treversing to BST.\n");
    postorderTreverse(root);
    printf("\n\n");

    search(root, 11);
    search(root, 6);

    return 0;
}