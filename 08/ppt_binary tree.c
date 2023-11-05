#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void displayPreorder(struct node* node)
{
    if(node == NULL)
        return;

    printf("%d ", node->data); //root

    displayPreorder(node->left); //subtree kiri

    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node* node)
{
    if(node == NULL)
        return;

    displayInorder(node->left); //subtree kiri

    printf("%d ", node->data); //root

    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node* node)
{
    if(node == NULL)
        return;

    displayPostorder(node->left); //subtree kiri

    displayPostorder(node->right); //subtree kanan

    printf("%d ", node->data); //root
}


struct node* insert(struct node* root, int newData) //Fungsi untuk menambahkan node baru dengan data = newData ke BST
{
    if(root == NULL)
    {
        root = newNode(newData);
    }
    else
    {
        int is_left = 0;
        struct node* cursor = root;
        struct node* prev = NULL;
        while(cursor != NULL)
        {
            prev = cursor;
            if(newData < cursor->data)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(newData > cursor->data)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }

        if(is_left == 1)
            prev->left = newNode(newData);
        else
            prev->right = newNode(newData);
    }

    return root;
}

struct node* delete_node(struct node* root, int deletedData)
{
    if(root == NULL)
        return;

    struct node* cursor;
    if(deletedData > root->data)
        root->right = delete_node(root->right, deletedData);
    else if(deletedData < root->data)
        root->left = delete_node(root->left, deletedData);
    else
    {
        //1 CHILD
        if(root->left == NULL){
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if(root->right == NULL) {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        //2 CHILDS NODE
        else{
            cursor = root->right;
            struct node* parent = NULL;

            while(cursor->left != NULL){
                parent = cursor;
                cursor = cursor->left;
            }

            root->data = cursor->data;
            if(parent != NULL){
                parent->left = delete_node(parent->left, parent->left->data);
            } else {
                root->right = delete_node(root->right, root->right->data);
            }
        }
    }

    return root;
}

void search_node(struct node* root, int data)
{
    struct node* cursor = root;

    while(cursor->data != data){
        if(cursor != NULL){
            if(cursor->data > data){
                cursor = cursor->left;
            }
            else {
                cursor = cursor->right;
            }

            if(cursor == NULL){
                printf("\nNode %d tidak ditemukan", data);
            }
        }
    }

    printf("\nNode %d ditemukan", data);
    return;
}
//int sum = 0;
//void sum_nodes(struct node* node){
//    if (node = NULL) return;
//
//    sum = sum + node->data;
//    sum_nodes(node->left);
//    sum_nodes(node->right);
//
//}

int sum_nodes(struct node* node)
{
    if(node == NULL)
        return 0;

    return (node->data + sum_nodes(node->left) + sum_nodes(node->right));
}

int find_maximum(struct node* node){
    if(node == NULL) return;
    while(node->right != NULL){
          node=node->right;
    }
    int max=node->data;
    return max;
}


int main()
{
//    struct node* root = newNode(8);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);

//    root->left = newNode(3);
//    root->left->left = newNode(1);
//    root->left->right = newNode(6);
//    root->left->right->left = newNode(4);
//    root->left->right->right = newNode(7);
//
//    root->right = newNode(10);
//    root->right->right = newNode(14);
//    root->right->right->left = newNode(13);

//    printf("\nIsi dari binary tree (Pre-order) adalah \n");
//    displayPreorder(root);
//
//    printf("\nIsi dari binary tree (In-order) adalah \n");
//    displayInorder(root);
//
//    printf("\nIsi dari binary tree (Post-order) adalah \n");
//    displayPostorder(root);

    struct node* root;
    root = newNode(20);
    root = insert(root,5);
    root = insert(root,1);
    root = insert(root,15);
    root = insert(root,9);
    root = insert(root,7);
    root = insert(root,12);
    root = insert(root,30);
    root = insert(root,25);
    root = insert(root,40);
    root = insert(root,45);
    root = insert(root,42);

    printf("Isi Tree: \n");
    displayInorder(root);

    printf("Jumlah = %d", sum_nodes(root));
//    printf("Min = %d", find_minimum(root));
    printf("Max = %d", find_maximum(root));

//    root = delete_node(root,1);
//
//    printf("\nIsi Tree (setelah delete): \n");
//    displayInorder(root);

    return 0;
}

